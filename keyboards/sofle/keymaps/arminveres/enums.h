#pragma once
#include QMK_KEYBOARD_H // IWYU pragma: keep

// Create an X macro to define layers and their names for printing later on OLED
#define MY_LAYERS                      \
    X_LAYER(_QWERTY, "Qwrt", "Base")   \
    X_LAYER(_GAMING, "Game", "Gaming") \
    X_LAYER(_LOWER, "", "Lower")       \
    X_LAYER(_UPPER, "", "Upper")       \
    X_LAYER(_ADJUST, "", "Adjust")

#define X_LAYER(layer, mode_name, layer_name) layer,
enum eSofleLayers { MY_LAYERS };
#undef X_LAYER

extern char const* gSofleModeNames[];
extern char const* gSofleLayerNames[];

enum eCustomKeycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_COLEMAK,
    // KC_PRVWD,
    // KC_NXTWD,
    // KC_LSTRT,
    // KC_LEND,
    // KC_DLINE
};
