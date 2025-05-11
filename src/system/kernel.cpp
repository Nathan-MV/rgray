#include "rgray/system/kernel.h"
#include <cstdlib>
#include "raylib.h"

// Get a random float between min and max included
float GetRandomFloat(float min, float max) {
  auto value = min + ((static_cast<float>(GetRandomValue(0, RAND_MAX)) / static_cast<float>(RAND_MAX)) * (max - min));
  return value;
}
