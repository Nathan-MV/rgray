#include "rgray/graphics/color.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Helper function to check if a string is numeric
bool is_numeric(const char *str) {
  while (*str) {
    if (!isdigit(*str)) return false;
    str++;
  }
  return true;
}

// Function to parse a hex string or number into a Color structure
Color ColorFromHex(const char *hex_arg) {
  Color color = {0, 0, 0, 255};
  unsigned int hex = 0;

  if (hex_arg == NULL) {
    // Handle the case where the input is NULL
    return color;  // Default color: black with full alpha
  }

  // Check if the input is a hex string
  if (hex_arg[0] == '#' || (strlen(hex_arg) >= 6 && isxdigit(hex_arg[0]))) {
    const char *hex_str = hex_arg;
    if (hex_str[0] == '#') hex_str++;  // Skip the '#'

    size_t len = strlen(hex_str);
    if (len == 6 || len == 8) {
      hex = strtoul(hex_str, NULL, 16);
      if (len == 6) hex |= 0xFF000000;  // Add full alpha if not present
    }
  }
  // Check if the input is a numeric string
  else if (is_numeric(hex_arg)) {
    hex = static_cast<unsigned int>(strtoul(hex_arg, NULL, 10));
  } else {
    // Invalid input, return default color
    return color;  // Default color: black with full alpha
  }

  // Parse the color components
  color.r = (hex >> 16) & 0xFF;
  color.g = (hex >> 8) & 0xFF;
  color.b = hex & 0xFF;
  color.a = (hex >> 24) & 0xFF;

  return color;
}

// Convert a single sRGB component (0–255) to linear space (0.0–1.0)
static inline float SRGBToLinear(unsigned char c) {
  auto cs = c / 255.0f;

  return (cs <= 0.04045f) ? (cs / 12.92f) : powf((cs + 0.055f) / 1.055f, 2.4f);
}

// Compute relative luminance in linear space from a Color
float ColorGetLuminance(Color color) {
  auto r = SRGBToLinear(color.r);
  auto g = SRGBToLinear(color.g);
  auto b = SRGBToLinear(color.b);

  return 0.2126f * r + 0.7152f * g + 0.0722f * b;
}
