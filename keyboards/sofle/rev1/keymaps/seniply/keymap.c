/* Seniply Layout for Sofle V1
 * 
 * Colemak-DH base layer with 6 layers following Seniply design:
 * - Layer 0: Base (Colemak-DH)
 * - Layer 1: Shift
 * - Layer 2: Extend (Navigation + One-shot modifiers)
 * - Layer 3: Symbols
 * - Layer 4: Function (F-keys + Media)
 * - Layer 5: Numbers
 *
 * See: https://stevep99.github.io/seniply/
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SHIFT,
    _EXTEND,
    _SYMBOLS,
    _FUNCTION,
    _NUMBERS
};

// One-shot modifier aliases
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RALT OSM(MOD_RALT)

// Layer tap/hold aliases
#define EXT_SPC LT(_EXTEND, KC_SPC)
#define SYM_ENT LT(_SYMBOLS, KC_ENT)
#define SFT_BSP LT(_SHIFT, KC_BSPC)
#define NUM_TAB LT(_NUMBERS, KC_TAB)

// Layer momentary
#define MO_EXT  MO(_EXTEND)
#define MO_SYM  MO(_SYMBOLS)
#define MO_FUN  MO(_FUNCTION)
#define MO_NUM  MO(_NUMBERS)
#define MO_SFT  MO(_SHIFT)

// Tri-layer: Extend + Symbols = Function
// This is handled in layer_state_set_user below

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE - Colemak-DH with apostrophe on semicolon position (Seniply default)
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctrl |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  -   |
 * |------+------+------+------+------+------| MUTE  |    | PLAY  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | Ext  | Shift| / Space /       \ Enter\  | Sym  | Num  | RAlt | RGUI |
 *            |      |      |      | Bspc |/       /         \      \ |      | Tab  |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
  KC_LCTL,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_MINS,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_MUTE,   KC_MPLY, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LGUI, KC_LALT, MO_EXT,  SFT_BSP, KC_SPC,  KC_ENT,  MO_SYM,  NUM_TAB, KC_RALT, KC_RGUI
),

/*
 * SHIFT Layer - Standard shifted characters
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  ~   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   "  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  _   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   <  |   >  |   ?  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SHIFT] = LAYOUT(
  _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                   S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TILD,
  _______, S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B),                   S(KC_J), S(KC_L), S(KC_U), S(KC_Y), KC_DQUO, KC_DEL,
  _______, S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G),                   S(KC_M), S(KC_N), S(KC_E), S(KC_I), S(KC_O), KC_UNDS,
  _______, S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V), _______, _______, S(KC_K), S(KC_H), KC_LT,   KC_GT,   KC_QUES, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * EXTEND Layer - Navigation and One-Shot Modifiers (DreymaR-style)
 *
 * Left side: One-shot modifiers (sticky) on home row
 * Right side: Navigation cluster
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Esc  | Copy | Find |Paste |      |                    | PgUp | Home |  Up  | End  | Del  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Alt  | GUI  |Shift | Ctrl |AltGr |-------.    ,-------| PgDn | Left | Down |Right | Bspc | Ins  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy |      |Paste |-------|    |-------|      | Tab  |      | Enter| App  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | #### |      | /       /       \      \  | Func |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 *
 * #### = Layer active indicator
 */
[_EXTEND] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_ESC,  C(KC_C), C(KC_F), C(KC_V), XXXXXXX,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_F12,
  _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_INS,
  _______, C(KC_Z), C(KC_X), C(KC_C), XXXXXXX, C(KC_V), _______, _______, XXXXXXX, KC_TAB,  XXXXXXX, KC_ENT,  KC_APP,  _______,
                    _______, _______, _______, _______, _______, _______, MO_FUN,  _______, _______, _______
),

/*
 * SYMBOLS Layer - Programming symbols
 *
 * Opening brackets on home positions (more common due to IDE auto-completion)
 * Each bracket type assigned to one finger
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   ~  |   `  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Alt  | GUI  |Shift | Ctrl |AltGr |-------.    ,-------|   ;  |   (  |   {  |   [  |   :  |   \  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   )  |   }  |   ]  |   =  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | Func |      | /       /       \      \  | #### |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, KC_GRV,  _______,
  _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,                   KC_SCLN, KC_LPRN, KC_LCBR, KC_LBRC, KC_COLN, KC_BSLS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PLUS, KC_RPRN, KC_RCBR, KC_RBRC, KC_EQL,  KC_PIPE,
                    _______, _______, MO_FUN,  _______, _______, _______, _______, _______, _______, _______
),

/*
 * FUNCTION Layer - F-keys, Media, and System controls
 *
 * Accessed by holding both Extend + Symbols (outer thumb keys)
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | BriDn| BriUp|      |      |      |                    | F12  |  F7  |  F8  |  F9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Alt  | GUI  |Shift | Ctrl |AltGr |-------.    ,-------|  F11 |  F4  |  F5  |  F6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Prev | Next | Vol- | Vol+ | Mute |-------|    |-------|  F10 |  F1  |  F2  |  F3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      | #### |      | /       /       \ Play \  | #### |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUNCTION] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   XXXXXXX, _______,
  _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   XXXXXXX, _______,
  _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_MPLY, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/*
 * NUMBERS Layer - Numpad-style number input
 *
 * Accessed via Num key (right thumb) or Sym + Shift
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   /  |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Alt  | GUI  |Shift | Ctrl |AltGr |-------.    ,-------|   *  |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   .  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      | #### |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMBERS] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
  _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, OS_RALT,                   KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, _______,
                    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

// Encoder functionality
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Base layer: Left = Volume, Right = Scroll
    [_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_SHIFT]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    // Extend layer: Left = Undo/Redo, Right = Word navigation
    [_EXTEND]   = { ENCODER_CCW_CW(C(KC_Z), C(KC_Y)), ENCODER_CCW_CW(C(KC_LEFT), C(KC_RGHT)) },
    // Symbols layer: Left = Tab switch, Right = Bracket navigation
    [_SYMBOLS]  = { ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)), ENCODER_CCW_CW(KC_LBRC, KC_RBRC) },
    // Function layer: Left = Brightness, Right = Media track
    [_FUNCTION] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    // Numbers layer: Left = Zoom, Right = History navigation
    [_NUMBERS]  = { ENCODER_CCW_CW(C(KC_MINS), C(KC_EQL)), ENCODER_CCW_CW(A(KC_LEFT), A(KC_RGHT)) },
};
#endif

// OLED display (if your Sofle has OLEDs)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

static void render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Colemak-DH"), false);
            break;
        case _SHIFT:
            oled_write_ln_P(PSTR("Shift"), false);
            break;
        case _EXTEND:
            oled_write_ln_P(PSTR("Extend"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
    }
}

static void render_mod_state(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_CTRL  ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_ALT   ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_ln_P(mods & MOD_MASK_GUI ? PSTR("GUI") : PSTR("   "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        render_mod_state();
    } else {
        // Secondary OLED - show Seniply logo or info
        oled_write_ln_P(PSTR("Seniply"), false);
        oled_write_ln_P(PSTR("Colemak-DH"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("6 Layers"), false);
    }
    return false;
}
#endif
