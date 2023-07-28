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

/// Increase Tapping term from the default 200ms to 220ms for better fast typing!
/// To do individual keys: https://docs.qmk.fm/#/tap_hold?id=tapping-term
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif

#define TAPPING_TERM 160

/// In combination with fast typing and home row mods, PERMISSIVE_HOLD enables to register keys instead of layer changes
/// For more information see: https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
#define PERMISSIVE_HOLD

/// Set encoder settings
#ifdef ENCODER_RESOLUTION
// Setting the resolution to 4 results in 10% increase e.g., in volume change. 2 is 20% so 8 should
// result in 5%
#    undef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif

/// Custom Definitions
// #define USE_HOMEROW_MODS
#define PARTIAL_HOME_MODS
