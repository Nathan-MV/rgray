#ifndef COLOR_H
#define COLOR_H

#include "rgray/raylib_values.h"

Color ColorFromHex(const char *hex_arg);
float ColorGetLuminance(Color color);

#endif  // COLOR_H
