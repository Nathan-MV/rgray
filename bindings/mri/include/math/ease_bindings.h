#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern "C" void Init_Ease();

// Macro to define easing methods
#define RB_METHOD_EASE(name, func)                                                                                     \
  static VALUE name(VALUE self, VALUE rb_symbol, VALUE rb_time, VALUE rb_begin, VALUE rb_change, VALUE rb_duration) {  \
    const float time = NUM2FLT(rb_time);                                                                              \
    const float begin = NUM2FLT(rb_begin);                                                                            \
    const float change = NUM2FLT(rb_change);                                                                           \
    const float duration = NUM2FLT(rb_duration);                                                                       \
                                                                                                                       \
    static ID id_in = rb_intern("in");                                                                                \
    static ID id_out = rb_intern("out");                                                                              \
    static ID id_inout = rb_intern("inout");                                                                          \
                                                                                                                       \
    ID symbol = SYM2ID(rb_symbol);                                                                                    \
    float result;                                                                                                      \
                                                                                                                       \
    if (symbol == id_in) {                                                                                            \
      result = func##In(time, begin, change, duration);                                                               \
    } else if (symbol == id_out) {                                                                                    \
      result = func##Out(time, begin, change, duration);                                                              \
    } else if (symbol == id_inout) {                                                                                  \
      result = func##InOut(time, begin, change, duration);                                                            \
    } else {                                                                                                          \
      const char* name = rb_id2name(symbol);                                                                          \
      rb_raise(rb_eArgError, "Unknown easing type: %s", name ? name : "<invalid>");                                   \
    }                                                                                                                 \
                                                                                                                       \
    return DBL2NUM(result);                                                                                           \
  }
