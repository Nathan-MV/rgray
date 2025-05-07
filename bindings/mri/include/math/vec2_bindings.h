#ifndef MRI_VEC2_H
#define MRI_VEC2_H

#include <algorithm>
#include <string>
#include <tuple>
#include "rgray/math/vec2.h"
#include "rgray/raylib_values.h"
#include "ruby_values.h"
#include "ruby_adapter.h"

extern VALUE rb_cVec2;
extern "C" void Init_Vec2();

#define RB_METHOD_VEC2_GETTER(name, member) \
  static auto name(VALUE self) {     \
    auto& vec2 = rb::get<Vector2>(self);     \
                                     \
    return INT2NUM(vec2.member);    \
  }

#define RB_METHOD_VEC2_SETTER(name, member)          \
  static auto name(VALUE self, VALUE value) { \
    auto& vec2 = rb::get<Vector2>(self);              \
    vec2.member = NUM2INT(value);            \
    return self;                              \
  }

#define RB_METHOD_VEC2(name, func)      \
  static auto name(VALUE self) { \
    auto& vec2 = rb::get<Vector2>(self); \
    vec2 = func(vec2);         \
    return self;                 \
  }

#define RB_METHOD_VEC2_FLOAT(name, func) \
  static auto name(VALUE self) {  \
    auto& vec2 = rb::get<Vector2>(self);  \
    auto result = func(vec2);    \
    return DBL2NUM(result);       \
  }

#define RB_METHOD_VEC2_OTHER(name, func)             \
  static auto name(VALUE self, VALUE other) { \
    auto& vec2 = rb::get<Vector2>(self);              \
    auto* other_vec2 = rb::get_safe<Vector2>(other, rb_cVec2);       \
    vec2 = func(vec2, *other_vec2);         \
    return self;                              \
  }

#define RB_METHOD_VEC2_OTHER_INT(name, func)           \
  static auto name(VALUE self, VALUE other) {   \
    auto& vec2_ptr = rb::get<Vector2>(self);            \
    auto* other_vec2 = rb::get_safe<Vector2>(other, rb_cVec2);         \
    auto result = func(vec2_ptr, *other_vec2); \
    return INT2NUM(result);                     \
  }

#define RB_METHOD_VEC2_OTHER_FLOAT(name, func)         \
  static auto name(VALUE self, VALUE other) {   \
    auto& vec2_ptr = rb::get<Vector2>(self);            \
    auto* other_vec2 = rb::get_safe<Vector2>(other, rb_cVec2);         \
    auto result = func(vec2_ptr, *other_vec2); \
    return DBL2NUM(result);                     \
  }

#define RB_METHOD_VEC2_SCALAR(name, func1, func2)    \
  static auto name(VALUE self, VALUE value) { \
    auto& vec2 = rb::get<Vector2>(self);              \
    if (rb_obj_is_kind_of(value, rb_cVec2)) { \
      auto* val = rb::get_safe<Vector2>(value, rb_cVec2);            \
      vec2 = func1(vec2, *val);             \
    } else {                                  \
      auto val = NUM2FLT(value);              \
      vec2 = func2(vec2, val);              \
    }                                         \
    return self;                              \
  }

#endif  // MRI_VEC2_H
