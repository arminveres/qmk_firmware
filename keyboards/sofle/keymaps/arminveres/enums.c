#include "enums.h"

#define X_LAYER(layer, mode_name, layer_name) mode_name,
char const* gSofleModeNames[] = {MY_LAYERS};
#undef X_LAYER

#define X_LAYER(layer, mode_name, layer_name) layer_name,
char const* gSofleLayerNames[] = {MY_LAYERS};
#undef X_LAYER
