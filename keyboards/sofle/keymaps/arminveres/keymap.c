#include QMK_KEYBOARD_H
#include "enums.h"
#include "achordion.h"
#include "sentence_case.h"
#include "home_row.h"

/*
 * Transparent layer
[_LOWER] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,                       _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______, _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
 */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────┬────────┬─────────────┬────────┬────────┬─────┐                             ┌─────┬────────┬────────┬────────┬───────────┬───────────────┐
//    │      esc      │   1    │      2      │   3    │   4    │  5  │                             │  6  │   7    │   8    │   9    │     0     │     bspc      │
//    ├───────────────┼────────┼─────────────┼────────┼────────┼─────┤                             ├─────┼────────┼────────┼────────┼───────────┼───────────────┤
//    │      tab      │   q    │      w      │   e    │   r    │  t  │                             │  y  │   u    │   i    │   o    │     p     │       \       │
//    ├───────────────┼────────┼─────────────┼────────┼────────┼─────┤                             ├─────┼────────┼────────┼────────┼───────────┼───────────────┤
//    │     lctl      │ HOME_A │   HOME_S    │ HOME_D │ HOME_F │  g  │                             │  h  │ HOME_J │ HOME_K │ HOME_L │ HOME_SCLN │   RCTL_T(')   │
//    ├───────────────┼────────┼─────────────┼────────┼────────┼─────┼────────────┐   ┌────────────┼─────┼────────┼────────┼────────┼───────────┼───────────────┤
//    │ OSM(MOD_LSFT) │   z    │      x      │   c    │   v    │  b  │    mute    │   │            │  n  │   m    │   ,    │   .    │     /     │ OSM(MOD_RSFT) │
//    └───────────────┴────────┼─────────────┼────────┼────────┼─────┼────────────┤   ├────────────┼─────┼────────┼────────┼────────┼───────────┴───────────────┘
//                             │ MO(_ADJUST) │  ralt  │  lgui  │ spc │ MO(_LOWER) │   │ MO(_LOWER) │ ent │  lgui  │  ralt  │        │                            
//                             └─────────────┴────────┴────────┴─────┴────────────┘   └────────────┴─────┴────────┴────────┴────────┘                            
[_QWERTY] = LAYOUT(
  KC_ESC        , KC_1   , KC_2        , KC_3    , KC_4    , KC_5   ,                               KC_6   , KC_7    , KC_8    , KC_9    , KC_0      , KC_BSPC        ,
  KC_TAB        , KC_Q   , KC_W        , KC_E    , KC_R    , KC_T   ,                               KC_Y   , KC_U    , KC_I    , KC_O    , KC_P      , KC_BSLS        ,
  KC_LCTL       , HOME_A , HOME_S      , HOME_D  , HOME_F  , KC_G   ,                               KC_H   , HOME_J  , HOME_K  , HOME_L  , HOME_SCLN , RCTL_T(KC_QUOT),
  OSM(MOD_LSFT) , KC_Z   , KC_X        , KC_C    , KC_V    , KC_B   , KC_MUTE    ,     _______    , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH   , OSM(MOD_RSFT)  ,
                           MO(_ADJUST) , KC_RALT , KC_LGUI , KC_SPC , MO(_LOWER) ,     MO(_LOWER) , KC_ENT , KC_LGUI , KC_RALT , _______                              
),

//    ┌───────────────┬───┬─────────────┬──────┬──────┬─────┐                             ┌─────┬──────┬──────┬─────┬───┬───────────────┐
//    │      esc      │ 1 │      2      │  3   │  4   │  5  │                             │  6  │  7   │  8   │  9  │ 0 │     bspc      │
//    ├───────────────┼───┼─────────────┼──────┼──────┼─────┤                             ├─────┼──────┼──────┼─────┼───┼───────────────┤
//    │      tab      │ q │      w      │  e   │  r   │  t  │                             │  y  │  u   │  i   │  o  │ p │       \       │
//    ├───────────────┼───┼─────────────┼──────┼──────┼─────┤                             ├─────┼──────┼──────┼─────┼───┼───────────────┤
//    │     lctl      │ a │      s      │  d   │  f   │  g  │                             │  h  │  j   │  k   │  l  │ ; │   RCTL_T(')   │
//    ├───────────────┼───┼─────────────┼──────┼──────┼─────┼────────────┐   ┌────────────┼─────┼──────┼──────┼─────┼───┼───────────────┤
//    │ OSM(MOD_LSFT) │ z │      x      │  c   │  v   │  b  │    mute    │   │            │  n  │  m   │  ,   │  .  │ / │ OSM(MOD_RSFT) │
//    └───────────────┴───┼─────────────┼──────┼──────┼─────┼────────────┤   ├────────────┼─────┼──────┼──────┼─────┼───┴───────────────┘
//                        │ MO(_ADJUST) │ ralt │ lgui │ spc │ MO(_LOWER) │   │ MO(_LOWER) │ ent │ lgui │ ralt │     │                    
//                        └─────────────┴──────┴──────┴─────┴────────────┘   └────────────┴─────┴──────┴──────┴─────┘                    
[_GAMING] = LAYOUT(
  KC_ESC        , KC_1 , KC_2        , KC_3    , KC_4    , KC_5   ,                               KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC        ,
  KC_TAB        , KC_Q , KC_W        , KC_E    , KC_R    , KC_T   ,                               KC_Y   , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS        ,
  KC_LCTL       , KC_A , KC_S        , KC_D    , KC_F    , KC_G   ,                               KC_H   , KC_J    , KC_K    , KC_L    , KC_SCLN , RCTL_T(KC_QUOT),
  OSM(MOD_LSFT) , KC_Z , KC_X        , KC_C    , KC_V    , KC_B   , KC_MUTE    ,     _______    , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , OSM(MOD_RSFT)  ,
                         MO(_ADJUST) , KC_RALT , KC_LGUI , KC_SPC , MO(_LOWER) ,     MO(_LOWER) , KC_ENT , KC_LGUI , KC_RALT , _______                            
),

//    ┌─────────┬─────┬─────┬─────┬─────┬─────┐                       ┌──────┬──────┬──────┬──────┬──────┬─────┐
//    │         │ f1  │ f2  │ f3  │ f4  │ f5  │                       │  f6  │  f7  │  f8  │  f9  │ f10  │ del │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                       ├──────┼──────┼──────┼──────┼──────┼─────┤
//    │         │  ~  │  {  │  }  │  +  │  =  │                       │ pgup │ home │      │      │      │ f11 │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┤                       ├──────┼──────┼──────┼──────┼──────┼─────┤
//    │ CW_TOGG │  `  │  [  │  ]  │  _  │  -  │                       │ left │ down │  up  │ rght │      │ f12 │
//    ├─────────┼─────┼─────┼─────┼─────┼─────┼─────────┐   ┌─────────┼──────┼──────┼──────┼──────┼──────┼─────┤
//    │         │     │     │     │     │     │ QK_BOOT │   │ QK_BOOT │ pgdn │ end  │ mprv │ mnxt │ mply │     │
//    └─────────┴─────┼─────┼─────┼─────┼─────┼─────────┤   ├─────────┼──────┼──────┼──────┼──────┼──────┴─────┘
//                    │     │     │     │     │         │   │         │      │      │      │      │             
//                    └─────┴─────┴─────┴─────┴─────────┘   └─────────┴──────┴──────┴──────┴──────┘             
[_LOWER] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9    , KC_F10  , KC_DEL ,
  _______ , KC_TILD , KC_LCBR , KC_RCBR , KC_PLUS , KC_EQL  ,                         KC_PGUP , KC_HOME , _______ , _______  , _______ , KC_F11 ,
  CW_TOGG , KC_GRV  , KC_LBRC , KC_RBRC , KC_UNDS , KC_MINS ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , KC_F12 ,
  _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT ,     QK_BOOT , KC_PGDN , KC_END  , KC_MPRV , KC_MNXT  , KC_MPLY , _______,
                      _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______                     
),

//    ┌─────────┬────┬─────────┬────────┬─────────┬─────┐               ┌─────┬──────┬──────┬──────┬────┬────┐
//    │   no    │ no │   no    │   no   │   no    │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼────┼─────────┼────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │ QK_BOOT │ no │ qWERTY  │ gAMING │ CG_TOGG │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼────┼─────────┼────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │ no │ CG_TOGG │   no   │   no    │ no  │               │ no  │ vold │ mute │ volu │ no │ no │
//    ├─────────┼────┼─────────┼────────┼─────────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │ no │   no    │   no   │   no    │ no  │ no  │   │ no  │ no  │ mprv │ mply │ mnxt │ no │ no │
//    └─────────┴────┼─────────┼────────┼─────────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼────┴────┘
//                   │         │        │         │     │     │   │     │     │      │      │      │          
//                   └─────────┴────────┴─────────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘          
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX   , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  QK_BOOT , XXXXXXX , KC_QWERTY , KC_GAMING , CG_TOGG , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , CG_TOGG   , XXXXXXX   , XXXXXXX , XXXXXXX ,                         XXXXXXX , KC_VOLD , KC_MUTE , KC_VOLU , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX   , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX,
                      _______   , _______   , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______                    
)
};
// clang-format on

#if 0
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _GAMING, _ADJUST);
}
#endif

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
#if 0
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
#endif
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}
