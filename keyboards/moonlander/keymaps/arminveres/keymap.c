#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "quantum.h"
#include "tap_dance.h"

#define CAPS_WORD QK_CAPS_WORD_TOGGLE

#define USE_HOMEROW_MODS
#ifdef USE_HOMEROW_MODS
// Left-hand home row mods
#    define HOME_A (LGUI_T(KC_A))
#    define HOME_S (LALT_T(KC_S))
#    define HOME_D (LCTL_T(KC_D))
#    define HOME_F (LSFT_T(KC_F))
// Right-hand home row mods
#    define HOME_J (RSFT_T(KC_J))
#    define HOME_K (RCTL_T(KC_K))
#    define HOME_L (LALT_T(KC_L))
#    define HOME_SCLN (RGUI_T(KC_SCLN))
#else
// Left-hand keys
#    define HOME_A (KC_A)
#    define HOME_S (KC_S)
#    define HOME_D (KC_D)
#    define HOME_F (KC_F)
// Right-hand keys
#    define HOME_J (KC_J)
#    define HOME_K (KC_K)
#    define HOME_L (KC_L)
// we are still using the KC_SCLN as a control replacement
#    define HOME_SCLN (RCTL_T(KC_SCLN))
#endif /* ifdef USE_HOMEROW_MODS */

enum custom_keycodes {
    RGB_SLD = SAFE_RANGE,
    HSV_0_255_255,
    HSV_86_255_128,
    HSV_172_255_255,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,   KC_1,           KC_2,      KC_3,      KC_4,      KC_5,           OSL(4),                       OSL(4),         KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPC,
    KC_TAB,      KC_Q,           KC_W,      KC_E,      KC_R,      KC_T,           KC_EQUAL,                     KC_MINUS,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    CAPS_WORD,   HOME_A,         HOME_S,    HOME_D,    HOME_F,    KC_G,           KC_LBRC,                      KC_RBRC,        KC_H,           HOME_J,         HOME_K,         HOME_L,         HOME_SCLN,      KC_QUOTE,
    KC_LSFT,     KC_Z,           KC_X,      KC_C,      KC_V,      KC_B,                                                         KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       LM(5,MOD_LSFT),
    CAPS_WORD,   KC_CAPS_LOCK,   _______,   KC_LALT,   KC_LGUI,   TD(DANCE_0),                                                  TD(DANCE_1),    KC_RGUI,        MT(MOD_LALT, KC_ESCAPE),_______, _______, _______,
                                                                  KC_SPACE,   MO(1),   MO(2),                   MO(2),   MO(1),   KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_GRAVE,       KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                                 _______, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_DELETE,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, KC_PGUP,        KC_HOME,        _______, _______, _______, KC_F11,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       _______, KC_F12,
    _______, _______, _______, _______, _______, _______,                                 KC_PGDN,      KC_END,         KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,_______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [2] = LAYOUT_moonlander(
    KC_TILD,        _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_UP,       _______, _______, KC_BRIGHTNESS_UP,                                _______, _______, _______,          _______, _______,          _______, _______,
    _______, _______,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______, KC_BRIGHTNESS_DOWN,                                                                _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_BTN1,     KC_MS_BTN2,     _______,                                                                                                 _______, _______, _______, _______, _______, RESET,
    _______, _______, _______,                 _______, _______, KC_WWW_BACK
  ),
  [3] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,                                 _______, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        _______,
    _______, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       _______,                                                                 _______, KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     _______,
    _______, _______, KC_CIRC,        KC_LBRC,    KC_RBRC,    KC_TILD,                                        KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLS,      _______,
    _______, KC_COMMA,       _______, _______, _______, _______,                                                                                                 _______, _______, KC_DOT,         _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
  [4] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        _______, _______, _______, _______, _______,
    RGB_VAD,        RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        RGB_HUI
  ),
  [5] = LAYOUT_moonlander(
    KC_TILD,        _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______,                 _______, _______, _______
  ),
};
// clang-format off

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_255_255:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,255,255);
        }
        return false;
      case HSV_86_255_128:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(86,255,128);
        }
        return false;
      case HSV_172_255_255:
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(172,255,255);
        }
        return false;
    }
  return true;
}
