# QMK Keymap

## Installation

1. [Set up qmk environment](https://docs.qmk.fm/newbs_getting_started)
2. Clone this repository

```bash
git clone https://github.com/jesalx/qmk-keymap
```

3. Use [external userspace](https://docs.qmk.fm/newbs_external_userspace) by running the following command while replacing `path/to/qmk-keymap` with the relative path to the cloned repository

```bash
qmk config user.overlay_dir="$(realpath path/to/qmk-keymap)"
```

4. Compile and flash the keymap

```bash
qmk flash -kb zsa/voyager -km jesal
```

If `dfu-util` is not installed, run the flash command inside `nix-shell`:

```bash
nix-shell -p dfu-util --run 'qmk flash -kb zsa/voyager -km jesal'
```

## Editing the layout

Edit only `keyboards/zsa/voyager/keymaps/jesal/keymap.c`. `zsa_voyager_jesal.json` (for viewing at [config.qmk.fm](https://config.qmk.fm)) and `keymap.svg` (the image below) are generated from it, as is the leader table at the bottom of this file (from `super_leader.def`). Regenerate all of them with [go-task](https://taskfile.dev):

```bash
task
```

## Layout

![Keymap layout](keymap.svg)

## Leader sequences

Tap the left thumb key (tap = leader, hold = GUI), then the keys below. Sequences are defined in `keyboards/zsa/voyager/keymaps/jesal/super_leader.def`.

<!-- leader:start -->
| Keys | Output | Description |
| --- | --- | --- |
| `L T` | `RM_TOGG` | Toggle RGB lighting |
| `L G` | `RGB_M_G` | Gradient lighting effect |
| `L U` | `RGBVALU` | Increase lighting brightness |
| `L D` | `RGBVALD` | Decrease lighting brightness |
| `L R` | `RGBRAND` | Random lighting palette |
| `L L` | `RGBDEF` | Reset lighting to the default |
| `T S` | `SOCDTOG` | Toggle SOCD cleaning |
| `T N` | `NK_TOGG` | Toggle NKRO |
| `T D` | `DB_TOGG` | Toggle QMK debug output |
| `F 1` | `KC_F1` | F1 |
| `F 2` | `KC_F2` | F2 |
| `F 3` | `KC_F3` | F3 |
| `F 4` | `KC_F4` | F4 |
| `F 5` | `KC_F5` | F5 |
| `F 6` | `KC_F6` | F6 |
| `F 7` | `KC_F7` | F7 |
| `F 8` | `KC_F8` | F8 |
| `F 9` | `KC_F9` | F9 |
| `F 0` | `KC_F10` | F10 |
| `F -` | `KC_F11` | F11 |
| `B B` | `KC_WBAK` | Browser back |
| `B R` | `KC_WREF` | Browser refresh |
| `B S` | `SRCHSEL` | Search the selection (or clipboard) in a new tab |
| `B N` | `XOS_NEWTAB` | New tab |
| `B C` | `XOS_CLOSETAB` | Close tab |
| `B T` | `XOS_REOPENTAB` | Reopen closed tab |
| `B U` | `URLCOPY` | Copy the page URL |
| `I N` | `"Jesal"` | Type name |
| `I W` | `"jesal.dev"` | Type website |
| `I G` | `"github.com/jesalx"` | Type GitHub URL |
<!-- leader:end -->
