#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    HSV_219_255_255,
    HSV_169_255_255,
    HSV_0_255_255,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_voyager(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
        KC_BSPC, KC_Q, KC_W, KC_E, KC_R, KC_T,                                  KC_Y, KC_U, KC_I, KC_O, KC_MINUS, KC_ENTER,
        KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,   KC_H, RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_P), KC_QUOTE,
        CW_TOGG, KC_Z, KC_X, KC_C, KC_V, KC_B,                                  KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, TO(3),
        LT(1, KC_SPACE), LT(3, KC_ENTER),                                       OSM(MOD_RSFT), KC_BSPC),

    [1] = LAYOUT_voyager(
        KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRANSPARENT, KC_GRAVE, KC_LABK, KC_SLASH, KC_RABK, KC_PERC,      KC_AMPR, KC_BSLS, KC_LCBR, KC_RCBR, KC_UNDS, KC_F12,
        KC_HASH, KC_CIRC, KC_MINUS, KC_EQUAL, KC_DLR, KC_DOT,               KC_AT, KC_COLN, KC_LPRN, KC_RPRN, KC_QUOTE, KC_SCLN,
        KC_TRANSPARENT, KC_TILD, KC_PLUS, KC_ASTR, KC_QUES, KC_COMMA,       KC_PIPE, KC_EXLM, KC_LBRC, KC_RBRC, KC_DQUO, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT,                                     KC_TRANSPARENT, KC_TRANSPARENT),

    [2] = LAYOUT_voyager(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_RCTL, KC_Z, KC_Q, KC_W, KC_E, KC_R,                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MAGIC_TOGGLE_NKRO, KC_TRANSPARENT,
        KC_TAB, KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_LEFT_ALT, OSL(4), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SCLN,
        KC_SPACE, KC_LEFT_CTRL,                                                                        KC_TRANSPARENT, KC_TRANSPARENT),

    [3] = LAYOUT_voyager(
        RGB_TOG, TOGGLE_LAYER_COLOR, RGB_MODE_FORWARD, RGB_SLD, RGB_VAD, RGB_VAI,           KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_TRANSPARENT, LALT(LCTL(KC_DELETE)),
        RGB_HUD, RGB_HUI, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS,                           KC_HOME, KC_PGDN, KC_PAGE_UP, KC_END, DT_PRNT, DT_UP,
        HSV_219_255_255, KC_TRANSPARENT, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,             KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PRINT_SCREEN, DT_DOWN,
        HSV_169_255_255, HSV_0_255_255, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0,                 KC_AUDIO_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NUM, TO(0),
        KC_TRANSPARENT, KC_TRANSPARENT,                                                     KC_TRANSPARENT, KC_TRANSPARENT),

    [4] = LAYOUT_voyager(
        KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS,         KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRANSPARENT, DT_UP,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, DT_PRNT, DT_DOWN,
        KC_TRANSPARENT, TO(2), KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_0,                      KC_AUDIO_MUTE, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_NUM, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT),
};
// clang-format on

const uint16_t PROGMEM combo0[] = {KC_GRAVE, KC_1, COMBO_END};
const uint16_t PROGMEM combo1[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo0, TG(2)),
    COMBO(combo1, KC_ESCAPE),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* If on the gaming layer, disable all combos except gaming layer toggle and ESC */
    if (layer_state_is(2) && combo_index != 0 && combo_index != 1) {
        return false;
    }

    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_A:
            return TAPPING_TERM + 50;
        case KC_P:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow one-handed chords within TAPPING_TERM for
    switch (tap_hold_keycode) {
        // Layer switches
        case LT(1, KC_SPACE):
            return true;
            break;

        case LT(3, KC_ENTER):
            return true;
            break;

        // alt-tab
        case LALT_T(KC_S):
            if (other_keycode == KC_TAB) {
                return true;
            }

        // ctrl-backspace
        case RCTL_T(KC_J):
            if (other_keycode == KC_BSPC) {
                return true;
            }
            break;

        // cut, copy, paste
        case LCTL_T(KC_F):
            if (other_keycode == KC_X || other_keycode == KC_C || other_keycode == KC_V) {
                return true;
            }
            break;
    }
    // Otherwise block chords on the same hand that PERMISSIVE_HOLD would allow within TAPPING_TERM
    return get_chordal_hold_default(tap_hold_record, other_record);
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {197, 255, 255}, {151, 255, 255}, {30, 255, 255}, {151, 255, 255}, {197, 255, 255}, {197, 255, 255}, {197, 255, 255}, {230, 255, 255}, {230, 255, 255}, {197, 255, 255}, {30, 255, 255}, {0, 0, 0}, {197, 255, 255}, {230, 255, 255}, {230, 255, 255}, {197, 255, 255}, {30, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {197, 255, 255}, {30, 255, 255}, {151, 255, 255}, {151, 255, 255}, {30, 255, 255}, {0, 0, 0}, {197, 255, 255}, {30, 255, 255}, {151, 255, 255}, {151, 255, 255}, {30, 255, 255}, {30, 255, 255}, {197, 255, 255}, {197, 255, 255}, {151, 255, 255}, {151, 255, 255}, {30, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [2] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 245, 245}, {0, 245, 245}, {219, 255, 255}, {0, 245, 245}, {0, 245, 245}, {0, 0, 0}, {131, 255, 255}, {217, 255, 255}, {217, 255, 255}, {217, 255, 255}, {0, 245, 245}, {131, 255, 255}, {131, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {217, 255, 255}, {217, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {219, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

    [3] = {{30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {30, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {219, 255, 255}, {0, 0, 0}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {169, 255, 255}, {0, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {0, 0, 0}, {0, 0, 0}, {231, 168, 251}, {231, 168, 251}, {231, 168, 251}, {231, 168, 251}, {0, 0, 0}, {249, 255, 255}, {122, 244, 233}, {122, 244, 233}, {122, 244, 233}, {122, 244, 233}, {0, 0, 0}, {0, 0, 0}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {141, 255, 255}, {0, 0, 0}, {0, 0, 0}, {231, 168, 251}, {231, 168, 251}, {231, 168, 251}, {231, 168, 251}, {141, 255, 255}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return false;
    }
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_219_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(219, 255, 255);
            }
            return false;
        case HSV_169_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(169, 255, 255);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
    }
    return true;
}
