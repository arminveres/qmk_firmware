/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once


#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#define TAPPING_TERM 145

#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

/// In combination with fast typing and home row mods, PERMISSIVE_HOLD enables to register keys instead of layer changes
/// For more information see: https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
#define PERMISSIVE_HOLD

#define USE_HOMEROW_MODS
