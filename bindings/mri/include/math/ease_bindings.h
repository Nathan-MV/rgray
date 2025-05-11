#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern "C" void Init_Ease();

// Macro to define easing methods
#define RB_METHOD_EASE(name, func)                                                                                    \
  static VALUE name(VALUE self, VALUE rb_symbol, VALUE rb_time, VALUE rb_begin, VALUE rb_change, VALUE rb_duration) { \
    const auto time = NUM2FLT(rb_time);                                                                               \
    const auto begin = NUM2FLT(rb_begin);                                                                             \
    const auto change = NUM2FLT(rb_change);                                                                           \
    const auto duration = NUM2FLT(rb_duration);                                                                       \
                                                                                                                      \
    float result;                                                                                                     \
                                                                                                                      \
    const auto symbol = SYM2ID(rb_symbol);                                                                            \
    if (symbol == rb_intern("in")) {                                                                                  \
      result = func##In(time, begin, change, duration);                                                               \
    } else if (symbol == rb_intern("out")) {                                                                          \
      result = func##Out(time, begin, change, duration);                                                              \
    } else if (symbol == rb_intern("inout")) {                                                                        \
      result = func##InOut(time, begin, change, duration);                                                            \
    } else {                                                                                                          \
      rb_raise(rb_eArgError, "Unknown easing type: %" PRIsVALUE, rb_symbol);                                          \
    }                                                                                                                 \
                                                                                                                      \
    return DBL2NUM(result);                                                                                           \
  }
