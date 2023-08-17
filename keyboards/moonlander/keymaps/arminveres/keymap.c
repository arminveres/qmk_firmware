#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "quantum.h"
#include "achordion.h"
#include "sentence_case.h"

#define CAPS_WORD CW_TOGG

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

#elif defined(PARTIAL_HOME_MODS)
// Left-hand home row mods
#    define HOME_A (LGUI_T(KC_A))
#    define HOME_S (LALT_T(KC_S))
#    define HOME_D (KC_D)
#    define HOME_F (KC_F)
// Right-hand home row mods
#    define HOME_J (KC_J)
#    define HOME_K (KC_K)
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

enum eCustomKeycodes {
    RGB_SLD = SAFE_RANGE, //
    HSV_0_255_255,        //
    HSV_86_255_128,       //
    HSV_172_255_255,      //
    KC_QWERTY,            //
    KC_GAMING
};

enum eLayers { _QWERTY, _SPECIAL, _GAMING, _ADJUST };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────┬────────┬────────┬────────┬───────────────┬──────────────┬──────┐   ┌──────┬──────────────┬───────────────┬───────────────────┬────────┬───────────┬───────────────┐
//    │      esc      │   1    │   2    │   3    │       4       │      5       │      │   │      │      6       │       7       │         8         │   9    │     0     │     bspc      │
//    ├───────────────┼────────┼────────┼────────┼───────────────┼──────────────┼──────┤   ├──────┼──────────────┼───────────────┼───────────────────┼────────┼───────────┼───────────────┤
//    │      tab      │   q    │   w    │   e    │       r       │      t       │  =   │   │  -   │      y       │       u       │         i         │   o    │     p     │       \       │
//    ├───────────────┼────────┼────────┼────────┼───────────────┼──────────────┼──────┤   ├──────┼──────────────┼───────────────┼───────────────────┼────────┼───────────┼───────────────┤
//    │ OSM(MOD_LCTL) │ HOME_A │ HOME_S │ HOME_D │    HOME_F     │      g       │  [   │   │  ]   │      h       │    HOME_J     │      HOME_K       │ HOME_L │ HOME_SCLN │   RCTL_T(')   │
//    ├───────────────┼────────┼────────┼────────┼───────────────┼──────────────┼──────┘   └──────┼──────────────┼───────────────┼───────────────────┼────────┼───────────┼───────────────┤
//    │ OSM(MOD_LSFT) │   z    │   x    │   c    │       v       │      b       │                 │      n       │       m       │         ,         │   .    │     /     │ OSM(MOD_RSFT) │
//    ├───────────────┼────────┼────────┼────────┼───────────────┼──────────────┼──────┐   ┌──────┼──────────────┼───────────────┼───────────────────┼────────┼───────────┼───────────────┤
//    │   caps_LOCK   │        │  esc   │  lalt  │     lgui      │              │ ralt │   │ ralt │              │     rgui      │ MT(MOD_LALT, esc) │        │           │               │
//    └───────────────┴────────┴────────┼────────┼───────────────┼──────────────┼──────┘   └──────┼──────────────┼───────────────┼───────────────────┼────────┴───────────┴───────────────┘
//                                      │  spc   │ OSL(_SPECIAL) │ OSL(_ADJUST) │                 │ OSL(_ADJUST) │ OSL(_SPECIAL) │        ent        │                                     
//                                      └────────┴───────────────┴──────────────┘                 └──────────────┴───────────────┴───────────────────┘                                     
[_QWERTY] = LAYOUT_moonlander(
  KC_ESC        , KC_1    , KC_2   , KC_3     , KC_4          , KC_5         , _______  ,     _______  , KC_6         , KC_7          , KC_8                    , KC_9    , KC_0      , KC_BSPC         ,
  KC_TAB        , KC_Q    , KC_W   , KC_E     , KC_R          , KC_T         , KC_EQUAL ,     KC_MINUS , KC_Y         , KC_U          , KC_I                    , KC_O    , KC_P      , KC_BSLS         ,
  OSM(MOD_LCTL) , HOME_A  , HOME_S , HOME_D   , HOME_F        , KC_G         , KC_LBRC  ,     KC_RBRC  , KC_H         , HOME_J        , HOME_K                  , HOME_L  , HOME_SCLN , RCTL_T(KC_QUOTE),
  OSM(MOD_LSFT) , KC_Z    , KC_X   , KC_C     , KC_V          , KC_B         ,                           KC_N         , KC_M          , KC_COMMA                , KC_DOT  , KC_SLASH  , OSM(MOD_RSFT)   ,
  KC_CAPS_LOCK  , _______ , KC_ESC , KC_LALT  , KC_LGUI       ,                KC_RALT  ,     KC_RALT  ,                KC_RGUI       , MT(MOD_LALT, KC_ESCAPE) , _______ , _______   , _______         ,
                                     KC_SPACE , OSL(_SPECIAL) , OSL(_ADJUST) ,                           OSL(_ADJUST) , OSL(_SPECIAL) , KC_ENTER                                                        
),

//    ┌───────────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬──────┬──────┬──────┬──────┬──────┬─────┐
//    │           │ f1  │ f2  │ f3  │ f4  │ f5  │     │   │     │  f6  │  f7  │  f8  │  f9  │ f10  │ del │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │  ~  │     │     │     │     │     │   │     │ pgup │ home │      │      │      │ f11 │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │ CAPS_WORD │  `  │     │     │     │     │     │   │     │ left │ down │  up  │ rght │      │ f12 │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┘   └─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │     │     │     │     │     │               │ pgdn │ end  │ mprv │ mnxt │ mply │     │
//    ├───────────┼─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │           │     │     │     │     │     │     │   │     │      │ vold │ volu │ mute │      │     │
//    └───────────┴─────┴─────┼─────┼─────┼─────┼─────┘   └─────┼──────┼──────┼──────┼──────┴──────┴─────┘
//                            │     │     │     │               │      │      │      │                    
//                            └─────┴─────┴─────┘               └──────┴──────┴──────┘                    
[_SPECIAL] = LAYOUT_moonlander(
  _______   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,     _______ , KC_F6   , KC_F7             , KC_F8               , KC_F9               , KC_F10              , KC_DELETE,
  _______   , KC_TILD , _______ , _______ , _______ , _______ , _______ ,     _______ , KC_PGUP , KC_HOME           , _______             , _______             , _______             , KC_F11   ,
  CAPS_WORD , KC_GRV  , _______ , _______ , _______ , _______ , _______ ,     _______ , KC_LEFT , KC_DOWN           , KC_UP               , KC_RIGHT            , _______             , KC_F12   ,
  _______   , _______ , _______ , _______ , _______ , _______ ,                         KC_PGDN , KC_END            , KC_MEDIA_PREV_TRACK , KC_MEDIA_NEXT_TRACK , KC_MEDIA_PLAY_PAUSE , _______  ,
  _______   , _______ , _______ , _______ , _______ ,           _______ ,     _______ ,           KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP     , KC_AUDIO_MUTE       , _______             , _______  ,
                                  _______ , _______ , _______ ,                         _______ , _______           , _______                                                                    
),

//    ┌───────────────┬─────┬─────┬──────┬───────────────┬──────────────┬──────┐   ┌──────┬──────────────┬───────────────┬───────────────────┬─────┬─────┬───────────────┐
//    │      esc      │  1  │  2  │  3   │       4       │      5       │      │   │      │      6       │       7       │         8         │  9  │  0  │     bspc      │
//    ├───────────────┼─────┼─────┼──────┼───────────────┼──────────────┼──────┤   ├──────┼──────────────┼───────────────┼───────────────────┼─────┼─────┼───────────────┤
//    │      tab      │  q  │  w  │  e   │       r       │      t       │  =   │   │  -   │      y       │       u       │         i         │  o  │  p  │       \       │
//    ├───────────────┼─────┼─────┼──────┼───────────────┼──────────────┼──────┤   ├──────┼──────────────┼───────────────┼───────────────────┼─────┼─────┼───────────────┤
//    │ OSM(MOD_LCTL) │  a  │  s  │  d   │       f       │      g       │  [   │   │  ]   │      h       │       j       │         k         │  l  │  ;  │   RCTL_T(')   │
//    ├───────────────┼─────┼─────┼──────┼───────────────┼──────────────┼──────┘   └──────┼──────────────┼───────────────┼───────────────────┼─────┼─────┼───────────────┤
//    │ OSM(MOD_LSFT) │  z  │  x  │  c   │       v       │      b       │                 │      n       │       m       │         ,         │  .  │  /  │ OSM(MOD_RSFT) │
//    ├───────────────┼─────┼─────┼──────┼───────────────┼──────────────┼──────┐   ┌──────┼──────────────┼───────────────┼───────────────────┼─────┼─────┼───────────────┤
//    │   caps_LOCK   │     │ esc │ lalt │     lgui      │              │ ralt │   │ ralt │              │     rgui      │ MT(MOD_LALT, esc) │     │     │               │
//    └───────────────┴─────┴─────┼──────┼───────────────┼──────────────┼──────┘   └──────┼──────────────┼───────────────┼───────────────────┼─────┴─────┴───────────────┘
//                                │ spc  │ OSL(_SPECIAL) │ OSL(_ADJUST) │                 │ OSL(_ADJUST) │ OSL(_SPECIAL) │        ent        │                            
//                                └──────┴───────────────┴──────────────┘                 └──────────────┴───────────────┴───────────────────┘                            
[_GAMING] = LAYOUT_moonlander(
  KC_ESC        , KC_1    , KC_2   , KC_3     , KC_4          , KC_5         , _______  ,     _______  , KC_6         , KC_7          , KC_8                    , KC_9    , KC_0     , KC_BSPC         ,
  KC_TAB        , KC_Q    , KC_W   , KC_E     , KC_R          , KC_T         , KC_EQUAL ,     KC_MINUS , KC_Y         , KC_U          , KC_I                    , KC_O    , KC_P     , KC_BSLS         ,
  OSM(MOD_LCTL) , KC_A    , KC_S   , KC_D     , KC_F          , KC_G         , KC_LBRC  ,     KC_RBRC  , KC_H         , KC_J          , KC_K                    , KC_L    , KC_SCLN  , RCTL_T(KC_QUOTE),
  OSM(MOD_LSFT) , KC_Z    , KC_X   , KC_C     , KC_V          , KC_B         ,                           KC_N         , KC_M          , KC_COMMA                , KC_DOT  , KC_SLASH , OSM(MOD_RSFT)   ,
  KC_CAPS_LOCK  , _______ , KC_ESC , KC_LALT  , KC_LGUI       ,                KC_RALT  ,     KC_RALT  ,                KC_RGUI       , MT(MOD_LALT, KC_ESCAPE) , _______ , _______  , _______         ,
                                     KC_SPACE , OSL(_SPECIAL) , OSL(_ADJUST) ,                           OSL(_ADJUST) , OSL(_SPECIAL) , KC_ENTER                                                       
),

//    ┌─────────┬────────┬────────┬──────┬──────┬─────┬─────────────────┐   ┌─────┬─────┬─────┬──────────┬─────┬─────┬──────┐
//    │ QK_BOOT │        │        │      │      │     │                 │   │     │     │     │          │     │     │      │
//    ├─────────┼────────┼────────┼──────┼──────┼─────┼─────────────────┤   ├─────┼─────┼─────┼──────────┼─────┼─────┼──────┤
//    │         │ qWERTY │ gAMING │ ms_u │      │     │  bRIGHTNESS_UP  │   │     │     │     │          │     │     │      │
//    ├─────────┼────────┼────────┼──────┼──────┼─────┼─────────────────┤   ├─────┼─────┼─────┼──────────┼─────┼─────┼──────┤
//    │         │        │  ms_l  │ ms_d │ ms_r │     │ bRIGHTNESS_DOWN │   │     │     │     │          │     │     │      │
//    ├─────────┼────────┼────────┼──────┼──────┼─────┼─────────────────┘   └─────┼─────┼─────┼──────────┼─────┼─────┼──────┤
//    │         │        │        │      │      │     │                           │     │     │          │     │     │      │
//    ├─────────┼────────┼────────┼──────┼──────┼─────┼─────────────────┐   ┌─────┼─────┼─────┼──────────┼─────┼─────┼──────┤
//    │         │        │        │ btn1 │ btn2 │     │                 │   │     │     │     │          │     │     │ boot │
//    └─────────┴────────┴────────┼──────┼──────┼─────┼─────────────────┘   └─────┼─────┼─────┼──────────┼─────┴─────┴──────┘
//                                │      │      │     │                           │     │     │ www_back │                   
//                                └──────┴──────┴─────┘                           └─────┴─────┴──────────┘                   
[_ADJUST] = LAYOUT_moonlander(
  QK_BOOT , _______   , _______    , _______    , _______     , _______ , _______            ,     _______ , _______ , _______ , _______     , _______ , _______ , _______,
  _______ , KC_QWERTY , KC_GAMING  , KC_MS_UP   , _______     , _______ , KC_BRIGHTNESS_UP   ,     _______ , _______ , _______ , _______     , _______ , _______ , _______,
  _______ , _______   , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , _______ , KC_BRIGHTNESS_DOWN ,     _______ , _______ , _______ , _______     , _______ , _______ , _______,
  _______ , _______   , _______    , _______    , _______     , _______ ,                                    _______ , _______ , _______     , _______ , _______ , _______,
  _______ , _______   , _______    , KC_MS_BTN1 , KC_MS_BTN2  ,           _______            ,     _______ ,           _______ , _______     , _______ , _______ , RESET  ,
                                     _______    , _______     , _______ ,                                    _______ , _______ , KC_WWW_BACK                              
)
};
// [4] = LAYOUT_moonlander(
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , _______       , _______        , _______         , _______            ,                         _______ , _______ , _______ , _______ , _______ , _______,
//   _______ , _______ , HSV_0_255_255 , HSV_86_255_128 , HSV_172_255_255 ,                      RGB_MOD ,     RGB_TOG ,           _______ , _______ , _______ , _______ , _______,
//                                       RGB_VAD        , RGB_VAI         , TOGGLE_LAYER_COLOR ,                         RGB_SLD , RGB_HUD , RGB_HUI
// )
// clang-format on

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case KC_QWERTY: {
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        }
        case KC_GAMING: {
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
        }
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
        case HSV_0_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
        case HSV_86_255_128:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(86, 255, 128);
            }
            return false;
        case HSV_172_255_255:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(172, 255, 255);
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}
