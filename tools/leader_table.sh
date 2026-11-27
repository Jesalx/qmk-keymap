#!/bin/sh
# Rewrites the leader sequence table in a README from super_leader.def.
#
# Usage: leader_table.sh <super_leader.def> <README.md>
#
# The table replaces everything between the `<!-- leader:start -->` and
# `<!-- leader:end -->` markers. Every SEQ_* line in the .def file must end in a
# `// description` comment.
set -eu

def=$1
readme=$2

for marker in 'leader:start' 'leader:end'; do
  grep -q "<!-- $marker -->" "$readme" || {
    echo "leader_table.sh: $readme has no <!-- $marker --> marker" >&2
    exit 1
  }
done

table=$(mktemp)
out=$(mktemp)
trap 'rm -f "$table" "$out"' EXIT

awk '
BEGIN {
  print "| Keys | Output | Description |"
  print "| --- | --- | --- |"
}
/^SEQ_[A-Z]+\(/ {
  line = $0
  desc = ""
  i = index(line, "//")
  if (i) {
    desc = substr(line, i + 2)
    line = substr(line, 1, i - 1)
    gsub(/^ +| +$/, "", desc)
  }
  if (desc == "") {
    print "leader_table.sh: missing // description: " $0 > "/dev/stderr"
    exit 1
  }
  rest = substr(line, index(line, ",") + 1)  # " (KC_B, KC_B), KC_WBAK)"
  sub(/^ *\(/, "", rest)
  q = index(rest, ")")
  keys = substr(rest, 1, q - 1)
  result = substr(rest, q + 1)
  sub(/^, */, "", result)
  sub(/\) *$/, "", result)
  gsub(/KC_/, "", keys)
  gsub(/MINS/, "-", keys)
  gsub(/, */, " ", keys)
  printf "| `%s` | `%s` | %s |\n", keys, result, desc
}
' "$def" > "$table"

awk -v table="$table" '
/<!-- leader:start -->/ {
  print
  while ((getline row < table) > 0) print row
  skip = 1
  next
}
/<!-- leader:end -->/ { skip = 0 }
!skip { print }
' "$readme" > "$out"

cat "$out" > "$readme"
