#include "features/palettefx.h"
#include "features/socd_cleaner.h"

enum layers {
    BASE,
    NAV,
    SYMBOLS,
    NUMPAD,
    SYSTEM,
};

enum custom_keycodes {
    SOCDTOG = SAFE_RANGE,
    MACTOG,
    XOS_UNDO,
    XOS_REDO,
    XOS_CUT,
    XOS_COPY,
    XOS_PASTE,
    XOS_SALL,
    XOS_FIND,
    XOS_SAVE,
    XOS_WORDL,
    XOS_WORDR,
    XOS_LINEL,
    XOS_LINER,
    XOS_WORDBS,
    XOS_WORDDEL,
};

// Tap starts a Super Leader sequence, hold is GUI. LEADER itself can't live in
// a mod-tap, so the tap is intercepted in process_record_user (KC_F24 is only
// a placeholder).
#define LEADER_GUI LGUI_T(KC_F24)

// XOS_* keys send the Linux or macOS flavor of a shortcut. The mode is
// auto-detected from the host; MACTOG overrides it (e.g. behind a KVM).
static bool mac_mode = false;

bool process_detected_host_os_user(os_variant_t os) {
    mac_mode = (os == OS_MACOS || os == OS_IOS);
    return true;
}

// Returns the keycode to send for an XOS_* key, or KC_NO for any other key.
static uint16_t os_shortcut(uint16_t keycode) {
    switch (keycode) {
    case XOS_UNDO:  return mac_mode ? G(KC_Z)          : C(KC_Z);
    case XOS_REDO:  return mac_mode ? G(S(KC_Z))       : C(S(KC_Z));
    case XOS_CUT:   return mac_mode ? G(KC_X)          : C(KC_X);
    case XOS_COPY:  return mac_mode ? G(KC_C)          : C(KC_C);
    case XOS_PASTE: return mac_mode ? G(KC_V)          : C(KC_V);
    case XOS_SALL:  return mac_mode ? G(KC_A)          : C(KC_A);
    case XOS_FIND:  return mac_mode ? G(KC_F)          : C(KC_F);
    case XOS_SAVE:  return mac_mode ? G(KC_S)          : C(KC_S);
    case XOS_WORDL: return mac_mode ? A(KC_LEFT)       : C(KC_LEFT);
    case XOS_WORDR: return mac_mode ? A(KC_RGHT)       : C(KC_RGHT);
    case XOS_LINEL: return mac_mode ? G(KC_LEFT)       : KC_HOME;
    case XOS_LINER: return mac_mode ? G(KC_RGHT)       : KC_END;
    case XOS_WORDBS:  return mac_mode ? A(KC_BSPC)     : C(KC_BSPC);
    case XOS_WORDDEL: return mac_mode ? A(KC_DEL)      : C(KC_DEL);
    }
    return KC_NO;
}

// Movement: left = R, right = S, up = D, down = T
socd_cleaner_t socd_opposing_pairs[] = {
    {{KC_R, KC_S}, SOCD_CLEANER_LAST},
    {{KC_D, KC_T}, SOCD_CLEANER_LAST},
};
const uint16_t socd_opposing_pairs_count = ARRAY_SIZE(socd_opposing_pairs);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint16_t shortcut = os_shortcut(keycode);
    if (shortcut != KC_NO) {
        // Register/unregister (not tap) so holding the key repeats it.
        if (record->event.pressed) {
            register_code16(shortcut);
        } else {
            unregister_code16(shortcut);
        }
        return false;
    }
    switch (keycode) {
    case LEADER_GUI:
        if (record->tap.count && record->event.pressed) {
            super_leader_start();
            return false;
        }
        break;
    case SOCDTOG:
        if (record->event.pressed) {
            socd_cleaner_enabled = !socd_cleaner_enabled;
        }
        return false;
    case MACTOG:
        if (record->event.pressed) {
            mac_mode = !mac_mode;
        }
        return false;
    }
    return process_record_socd_cleaner(keycode, record);
};

void keyboard_post_init_user(void) {
    layer_state_set_user(layer_state);
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

// LED indices under the arrow keys (LEFT, DOWN, UP, RGHT) on the right-hand
// home row; see the rgb_matrix layout in keyboards/zsa/voyager/keyboard.json.
#define NAV_ARROWS_LED_FIRST 38
#define NAV_ARROWS_LED_LAST 41

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case NAV:
            for (uint8_t i = NAV_ARROWS_LED_FIRST; i <= NAV_ARROWS_LED_LAST; i++) {
                rgb_matrix_set_color(i, 129, 216, 208);
            }
            break;
    }
    return false;
}
