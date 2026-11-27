# QMK Keymap

![Keymap layout](keymap.svg)

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

Edit only `keyboards/zsa/voyager/keymaps/jesal/keymap.c`. `zsa_voyager_jesal.json` (for viewing at [config.qmk.fm](https://config.qmk.fm)) and `keymap.svg` (the image above) are generated from it. Regenerate both with [go-task](https://taskfile.dev):

```bash
task
```
