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
    }
    return true;
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            rgb_matrix_set_color_all(200, 100, 30);
            break;
        case 1:
            rgb_matrix_set_color_all(255, 0, 0);
            break;
        case 2:
            rgb_matrix_set_color_all(0, 255, 0);
            break;
        case 3:
            rgb_matrix_set_color_all(255, 255, 0);
            break;
        case 4:
            rgb_matrix_set_color_all(100, 100, 255);
            break;
        case 5:
            rgb_matrix_set_color_all(0, 255, 255);
            break;
        case 6:
            rgb_matrix_set_color_all(100, 0, 255);
            break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_set_color_all(200, 100, 30);
}
