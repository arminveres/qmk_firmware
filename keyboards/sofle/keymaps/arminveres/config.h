/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#pragma once

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT

/// To do individual keys: https://docs.qmk.fm/#/tap_hold?id=tapping-term
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
/// Change Tapping Term from the default 200ms!
#define TAPPING_TERM 200

/// In combination with fast typing and home row mods, PERMISSIVE_HOLD enables to register keys instead of layer changes
/// For more information see: https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
#define PERMISSIVE_HOLD

/// Set encoder settings
#ifdef ENCODER_RESOLUTION
// Setting the resolution to 4 results in 10% increase e.g., in volume change. 2 is 20% so 8 should
// result in 5%
// WARN: using 8 does not correctly increment the volume by 5%
#    undef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 20000 // 120000 = 2 minutes in ms.
#    define OLED_BRIGHTNESS 50 // Default 100.
#    define SPLIT_WPM_ENABLE   // Enable WPM across split keyboards (+268).
#    define SPLIT_OLED_ENABLE  // Synx on/off OLED state between halves (+100).
#endif                         // OLED_ENABLE

/// Left side is the master as plugged in to usb
#define MASTER_LEFT

/// Custom Definitions
// #define USE_HOMEROW_MODS
#define PARTIAL_HOME_MODS
#define USE_WPM_OLED
