/// Add custom defines, that are valid for all my keymaps
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


/// My Defines
#define USE_HOMEROW_MODS
// #define PARTIAL_HOME_MODS

/// Achordion defines
// Suppress tap-hold mods withing a typing streak
#define ACHORDION_STREAK
