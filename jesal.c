#include "features/palettefx.h"

enum layers {
    BASE,
    NAV,
    SYMBOLS,
    QWERTY,
    GAME,
    NUMPAD,
    SYSTEM,
};

enum custom_keycodes {
    USERNAME = SAFE_RANGE,
    USERSITE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case USERNAME:
        if (record->event.pressed) {
            SEND_STRING_DELAY("jesal", TAP_CODE_DELAY);
        }
        break;
    case USERSITE:
        if (record->event.pressed) {
            SEND_STRING_DELAY("jesal.dev", TAP_CODE_DELAY);
        }
        break;
    // We can't normally use a shifted key (minus -> underscore) with a mod tap
    // so we can intercept the keypress and send the shifted keypress instead
    case LGUI_T(KC_UNDERSCORE):
        if (record->tap.count && record->event.pressed) {
            tap_code16(KC_UNDERSCORE);
            return false;
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_VORTEX);
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * PALETTEFX_AFTERBURN, 255, 255);
    rgb_matrix_set_speed_noeeprom(128);
    rgb_matrix_enable_noeeprom();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state|default_layer_state)) {
        case BASE:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_VORTEX);
            rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * PALETTEFX_AFTERBURN, 255, 255);
            break;
        case NAV:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(0, 0, 0);
            break;
        case SYMBOLS:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_SPARKLE);
            rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * PALETTEFX_AFTERBURN, 255, 255);
            break;
        case QWERTY:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(43, 255, 255); // Yellow
            break;
        case GAME:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_SPARKLE);
            rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * PALETTEFX_PHOSPHOR, 255, 255);
            break;
        case NUMPAD:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(128, 255, 255); // Cyan
            break;
        case SYSTEM:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(213, 255, 255); // Purple
            break;
    }
    return state;
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case NAV:
            rgb_matrix_set_color(38, 129, 216, 208);
            rgb_matrix_set_color(39, 129, 216, 208);
            rgb_matrix_set_color(40, 129, 216, 208);
            rgb_matrix_set_color(41, 129, 216, 208);
            break;
    }
    return false;
}
