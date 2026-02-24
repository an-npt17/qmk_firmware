# Seniply Keymap for Sofle V1

A QMK implementation of the [Seniply](https://stevep99.github.io/seniply/) layout
with Colemak-DH as the base layer.

## Layers

| Layer | Activation | Description |
|-------|------------|-------------|
| 0 - Base | Default | Colemak-DH with `'` on `;` position |
| 1 - Shift | Hold inner-left thumb | Shifted characters |
| 2 - Extend | Hold outer-left thumb | Navigation + One-shot modifiers |
| 3 - Symbols | Hold outer-right thumb | Programming symbols |
| 4 - Function | Hold Extend + Symbols | F-keys, media, brightness |
| 5 - Numbers | Hold Num key | Numpad-style numbers |

## Key Features

- **One-shot modifiers** on Extend/Symbols layers (home row: Alt, GUI, Shift, Ctrl, AltGr)
- **Caps Word** enabled - double-tap Shift to activate, auto-disables after space
- **Encoder support**:
  - Base: Volume (left), Scroll (right)
  - Extend: Undo/Redo (left), Word nav (right)
  - Function: Brightness (left), Media track (right)

## Building

```bash
# Copy keymap to QMK firmware directory
cp -r ~/nixos-config/keyboards/sofle/keymaps/seniply \
      ~/qmk_firmware/keyboards/sofle/rev1/keymaps/

# Compile
qmk compile -kb sofle/rev1 -km seniply

# Flash (put keyboard in bootloader mode first)
qmk flash -kb sofle/rev1 -km seniply
```

## Customization

Edit `keymap.c` to customize the layout. Key reference:
- `KC_*` - Standard keycodes
- `S(KC_*)` - Shifted keycode
- `C(KC_*)` - Ctrl + keycode
- `A(KC_*)` - Alt + keycode
- `OSM(MOD_*)` - One-shot modifier
- `MO(layer)` - Momentary layer activation
- `LT(layer, KC_*)` - Layer-tap (tap for keycode, hold for layer)
