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

