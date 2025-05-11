#pragma once

#include <cmath>
#include <iomanip>
#include <sstream>
#include "rgray/graphics/color.h"
#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cColor;
extern "C" void Init_Color();

// Macro to define getter methods
#define RB_METHOD_COLOR_GETTER(name, member) \
  static VALUE name(VALUE self) {            \
    auto& color = rb::get<Color>(self);      \
    return CHR2FIX(color.member);            \
  }

// Macro to define setter methods
#define RB_METHOD_COLOR_SETTER(name, member)                     \
  static VALUE name(VALUE self, VALUE value) {                   \
    auto& color = rb::get<Color>(self);                          \
    const auto val = NUM2INT(value);                             \
    if (val < 0 || val > 255) {                                  \
      rb_raise(rb_eArgError, "value must be between 0 and 255"); \
    }                                                            \
    color.member = (unsigned char)val;                           \
    return self;                                                 \
  }
