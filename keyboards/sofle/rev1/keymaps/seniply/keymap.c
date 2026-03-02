/* Seniply Layout for Sofle V1
 *
 * 6-layer Seniply-style layout with Colemak/QWERTY dual base:
 * - Layer 0: Colemak-DH (default)
 * - Layer 1: QWERTY (alternative base)
 * - Layer 2: Extend (navigation)
 * - Layer 3: Symbols
 * - Layer 4: Numbers
 * - Layer 5: Function/Adjust
 *
 * See: https://stevep99.github.io/seniply/
 */

#include QMK_KEYBOARD_H

enum layers { _COLEMAK = 0, _QWERTY, _EXTEND, _SYMBOLS, _NUMBERS, _FUNCTION };

// One-shot modifier aliases
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RALT OSM(MOD_RALT)

// Layer aliases
#define MO_EXT MO(_EXTEND)
#define MO_SYM MO(_SYMBOLS)
#define MO_NUM MO(_NUMBERS)
#define MO_FUN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: COLEMAK-DH (Default Base Layer)
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------| MUTE  |    |  NO   |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LGUI | LAlt |MO_EXT| / Enter /       \ Space\  |MO_SYM| RAlt | RGUI | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_COLEMAK] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_MUTE, KC_NO, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, MO_EXT, KC_ENT, KC_SPC, MO_SYM, KC_RALT, KC_RGUI, KC_RCTL),

    /*
     * Layer 1: QWERTY (Alternative Base Layer)
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------| MUTE  |    |  NO   |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LGUI | LAlt |MO_EXT| / Enter /       \ Space\  |MO_SYM| RAlt | RGUI | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, MO_EXT, KC_ENT, KC_SPC, MO_SYM, KC_RALT, KC_RGUI, KC_RCTL),

    /*
     * Layer 2: EXTEND (Navigation Layer)
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Esc  |  NO  |  NO  |  NO  |  NO  |                    | PgUp | Home |  Up  | End  | Caps |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Alt  | GUI  |Shift | Ctrl | RAlt |-------.    ,-------| PgDn | Left | Down | Right| Del  |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      | C_Z  | C_X  | C_C  | C_V  |  NO  |-------|    |-------|  NO  | Bspc | Tab  | Enter| Ins  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /       /       \      \  |MO_FUN|      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_EXTEND] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS, _______, _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_RALT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, _______, _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_NO, _______, _______, KC_NO, KC_BSPC, KC_TAB, KC_ENT, KC_INS, _______, _______, _______, _______, _______, _______, _______, MO_FUN, _______, _______, _______),

    /*
     * Layer 3: SYMBOLS
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   !  |   @  |   #  |   $  |   %  |                    |   =  |   `  |   :  |   ;  |   +  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Alt  | GUI  |Shift | Ctrl |   ^  |-------.    ,-------|   *  |   (  |   {  |   [  |   -  |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |   `  |   ~  |   \  |   |  |   &  |-------|    |-------|   ~  |   )  |   }  |   ]  |   _  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |MO_FUN| /       /       \      \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_SYMBOLS] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_EQL, KC_GRV, KC_COLN, KC_SCLN, KC_PLUS, _______, _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_CIRC, KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS, _______, _______, KC_GRV, KC_TILD, KC_BSLS, KC_PIPE, KC_AMPR, _______, _______, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, _______, _______, _______, _______, MO_FUN, _______, _______, _______, _______, _______, _______),

    /*
     * Layer 4: NUMBERS
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   ;  |   :  |  NO  |  NO  |  NO  |                    |   =  |   7  |   8  |   9  |   +  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | Alt  | GUI  |Shift | Ctrl |  NO  |-------.    ,-------|   *  |   4  |   5  |   6  |   -  | Enter|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |  NO  |  NO  |  NO  |  NO  |  NO  |-------|    |-------|   0  |   1  |   2  |   3  |   /  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /       /       \ Space\  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMBERS] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, _______, KC_SCLN, KC_COLN, KC_NO, KC_NO, KC_NO, KC_EQL, KC_7, KC_8, KC_9, KC_PLUS, KC_DEL, _______, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, KC_NO, KC_ASTR, KC_4, KC_5, KC_6, KC_MINS, KC_ENT, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_SLSH, _______, _______, _______, _______, _______, _______, KC_SPC, _______, _______, _______, _______),

    /*
     * Layer 5: FUNCTION (F-keys, Media, Adjust)
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | BOOT |  NO  |  NO  |  NO  |  NO  |  NO  |                    |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  NO  |DF(0) |DF(1) |  NO  |  NO  |  NO  |                    | F12  |  F7  |  F8  |  F9  | PScr |  NO  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  NO  | Alt  | GUI  |Shift | Ctrl |CG_TG |-------.    ,-------| F11  |  F4  |  F5  |  F6  | ScrLk|  NO  |
     * |------+------+------+------+------+------|  NO   |    |  NO   |------+------+------+------+------+------|
     * |  NO  |  NO  |  NO  |  NO  |  NO  |  NO  |-------|    |-------| F10  |  F1  |  F2  |  F3  | Pause|  NO  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /       /       \ Play \  |      | Next | VolDn| VolUp|
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_FUNCTION] = LAYOUT(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(0), DF(1), KC_NO, KC_NO, KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, KC_NO, KC_NO, OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, CG_TOGG, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, KC_NO, _______, _______, _______, _______, _______, KC_MPLY, _______, KC_MNXT, KC_VOLD, KC_VOLU)};

// Encoder functionality
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_COLEMAK] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [_QWERTY] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [_EXTEND] = {ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)}, [_SYMBOLS] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)}, [_NUMBERS] = {ENCODER_CCW_CW(C(KC_Z), C(KC_Y)), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)}, [_FUNCTION] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
};
#endif

// OLED display
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

static void render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _EXTEND:
            oled_write_ln_P(PSTR("Extend"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
    }
}

static void render_default_layer(void) {
    oled_write_P(PSTR("Base: "), false);
    if (default_layer_state & (1 << _QWERTY)) {
        oled_write_ln_P(PSTR("QWERTY"), false);
    } else {
        oled_write_ln_P(PSTR("Colemak"), false);
    }
}

static void render_mod_state(void) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("Mods: "), false);
    oled_write_P(mods & MOD_MASK_SHIFT ? PSTR("SFT ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_CTRL ? PSTR("CTL ") : PSTR("    "), false);
    oled_write_P(mods & MOD_MASK_ALT ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_ln_P(mods & MOD_MASK_GUI ? PSTR("GUI") : PSTR("   "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        render_default_layer();
        render_mod_state();
    } else {
        oled_write_ln_P(PSTR("Seniply"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("Colemak/QWERTY"), false);
        oled_write_ln_P(PSTR("6 Layers"), false);
    }
    return false;
}
#endif
