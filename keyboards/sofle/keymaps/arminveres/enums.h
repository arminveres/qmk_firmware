#include QMK_KEYBOARD_H

enum eSofleLayers {
    _QWERTY,
    _LOWER,
    _GAMING,
    _ADJUST,
};

enum eCustomKeycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};
