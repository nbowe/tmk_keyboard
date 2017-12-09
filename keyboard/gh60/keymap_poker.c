#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
         ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSPC,  GRV, \
         TAB,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSLS, PGUP, \
        CAPS,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,        ENT, PGDN, \
        LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH,       RSFT,   UP,  FN0, \
        LCTL, LGUI, LALT,              SPC,                   PAUS, HOME,  END, LEFT, DOWN, RGHT),

    /* 1: FN layer
     * FN + ESC = MUTE
     * FN + 1-0 = F1-F10
     * FN + - = F11
     * FN + = = F12
     * FN + BSPC = DEL
     * FN + BSLS = INS
     * FN + PGUP = VOLU
     * FN + PGDN = VOLD
     * FN + C = CALC
     */
    KEYMAP(
        MUTE,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  DEL, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  INS, VOLU, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, VOLD, \
        TRNS, TRNS, TRNS, CALC, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, PGUP, TRNS, \
        TRNS, TRNS, TRNS,             TRNS,                   MPLY, MPRV, MNXT, HOME, PGDN,  END),

    /* 2: FN+LSHIFT layer 
     * FN+LSHIFT+ESC = SLEEP
     * FN+LSFT+SPC = mouse control
     */
    KEYMAP(
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, \
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS, \
        TRNS, TRNS, TRNS,             TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [1] = ACTION_LAYER_MOMENTARY(2),  // to Fn overlay
};
