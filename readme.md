# ZSA Voyager QMK Layouts

This repo contain
QMK files for the ZSA Voyager. Intended for use with ZSA's fork of QMK. Layouts currently built againt zsa/qmk_firmware firmware24.

# Intended usage

1. Clone/fork ZSA's fork of QMK, or fork the original QMK repo, add [zsa/qmk_firmware](https://github.com/zsa/qmk_firmware/) as a remote and switch to the relevant release branch (e.g., firmware24)

2. Inside the QMK repo, clone this repository into the `keyboards/zsa/voyager/keymaps` directory

3. At the top evel of the QMK repo, run `make zsa/voyager:mylayoutname`

4. Flash the output .bin file to the keyboard using either the Keymapp application or QMK CLI

## Features

All layouts make use of these features:

### Game layer

- Activated by pressing the two leftmost keys of the top row together
- Shifts the layout of the left hand by 1 key to the right, so WSAD are in a more comfortable postion
- Dedicated Ctrl, Alt, Shift keys
- All combos that use the homerow are disabled in this mode. Other combos may remain active

## Layouts

### combo-osm

Uses combinations of homerow keys to trigger modifiers when pressed together (or within COMBO_TERM of each other). Examples:

- F-D -> L-Ctrl

- D-S -> L-Shift

- S-A -> L-Alt

- A-Z -> L-GUI

The same combos are mirrored on the right hand. Note that GUI is an exception: it uses the pinky homerow key and the key below it.
