#pragma once

#define TAP_CODE_DELAY 5

#define TAPPING_TERM 125
#define PERMISSIVE_HOLD

// Hold shift for lower case
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 10 seconds
#define CAPS_WORD_IDLE_TIMEOUT 10000

// Each keypress takes two entries, so this fits about 128 keypresses shared
// between both dynamic macros (default is 128).
#define DYNAMIC_MACRO_SIZE 256

#define RGB_MATRIX_DEFAULT_SPD 127

// PaletteFx effects/palettes
#define PALETTEFX_SPARKLE_ENABLE
#define PALETTEFX_VORTEX_ENABLE

// All palettes, so the leader's random palette has something to pick from.
#define PALETTEFX_ENABLE_ALL_PALETTES
