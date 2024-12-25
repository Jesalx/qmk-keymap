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

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
}

// Change RGB Matrix color based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state|default_layer_state)) {
        case 0:
            rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            break;
        case 1:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(0, 255, 255);  // Red
            break;
        case 2:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(85, 255, 255); // Green
            break;
        case 3:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(43, 255, 255); // Yellow
            break;
        case 4:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(170, 255, 255); // Blue
            break;
        case 5:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(128, 255, 255); // Cyan
            break;
        case 6:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(213, 255, 255); // Purple
            break;
    }
    return state;
}
