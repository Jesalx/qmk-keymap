#include QMK_KEYBOARD_H

#include "voyager.h"
#include "jesal.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_B, KC_L, KC_D, KC_W, KC_Z, KC_J, KC_F, KC_O, KC_U, KC_QUOT, KC_MINS, KC_LCTL, KC_N, KC_R, KC_T, KC_S, KC_G, KC_Y, KC_H, KC_A, KC_E, KC_I, KC_SLSH, KC_LSFT, KC_Q, KC_X, KC_M, KC_C, KC_V, KC_K, KC_P, KC_COMM, KC_SCLN, KC_DOT, MT(MOD_RSFT, KC_ENT), KC_SPC, KC_LGUI, LT(2,KC_BSPC), LT(1,KC_ESC)),
    [1] = LAYOUT(TO(3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(6), TO(5), TO(4), KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_TRNS, KC_NO, KC_MINS, KC_PLUS, KC_EQL, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_ASTR, KC_NO, KC_NO, KC_NO, KC_NO, KC_COMM, KC_SCLN, KC_DOT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0), USERSITE, USERNAME, KC_LT, KC_GT, KC_BSLS, KC_GRV, KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_NO, KC_NO, CW_TOGG, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL, KC_HASH, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, KC_NO, DM_REC1, DM_PLY1, KC_SLSH, KC_ASTR, KC_CIRC, KC_AT, KC_TILD, KC_DLR, KC_LCBR, KC_RCBR, KC_NO, LSFT(KC_ENT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TO(0), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [4] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TO(0), KC_TAB, KC_B, KC_L, KC_D, KC_W, KC_Z, KC_J, KC_F, KC_O, KC_U, KC_QUOT, KC_MINS, KC_LCTL, KC_N, KC_R, KC_T, KC_S, KC_G, KC_Y, KC_H, KC_A, KC_E, KC_I, KC_SLSH, KC_LSFT, KC_Q, KC_X, KC_M, KC_C, KC_V, KC_K, KC_P, KC_COMM, KC_SCLN, KC_DOT, MT(MOD_RSFT, KC_ENT), KC_SPC, KC_LGUI, LT(2,KC_BSPC), LT(1,KC_ESC)),
    [5] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PEQL, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC),
    [6] = LAYOUT(KC_NO, RGB_TOG, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_F10, KC_F11, KC_TRNS, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, NK_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};
