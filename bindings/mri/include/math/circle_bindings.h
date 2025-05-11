#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

// Ruby class reference for Circle
extern VALUE rb_cCircle;

// Binding initialization function
extern "C" void Init_Circle();

// Circle, 3 components
typedef struct Circle {
  Vector2 center;  // Circle center position (Vector2)
  float radius;    // Circle radius
} Circle;
