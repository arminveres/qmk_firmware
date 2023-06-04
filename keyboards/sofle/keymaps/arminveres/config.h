#pragma once

/// Reduce Tapping term from the default 200ms to 150ms as I use it everywhere else for better
/// reaction
/// To do individual keys: https://docs.qmk.fm/#/tap_hold?id=tapping-term
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#    define TAPPING_TERM 150
#endif

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
