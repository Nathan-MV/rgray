#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cRect;
extern "C" void Init_Rect();

#define RB_METHOD_RECT_GETTER(name, member)   \
  static VALUE name(VALUE self) {             \
    auto& rect = rb::get<RayRectangle>(self); \
                                              \
    return DBL2NUM(rect.member);              \
  }

#define RB_METHOD_RECT_SETTER(name, member)    \
  static VALUE name(VALUE self, VALUE value) { \
    auto& rect = rb::get<RayRectangle>(self);  \
                                               \
    rect.member = NUM2FLT(value);              \
                                               \
    return self;                               \
  }
