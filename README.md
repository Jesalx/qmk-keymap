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
