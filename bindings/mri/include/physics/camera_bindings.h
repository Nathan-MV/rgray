#ifndef CAMERA_H
#define CAMERA_H

#include "ruby_values.h"
#include "ruby_adapter.h"
#include "rgray/raylib_values.h"

extern VALUE rb_cCamera;
extern "C" void Init_Camera();

#define RB_METHOD_CAMERA_GETTER_VEC2(name, member)                           \
  static VALUE name(VALUE self) {                                            \
    auto& camera = rb::get<Camera2D>(self);                                         \
    return rb::alloc_borrowed<Vector2>(rb_cVec2, &camera.member);                                        \
  }

#define RB_METHOD_CAMERA_SETTER_VEC2(name, member)    \
  static VALUE name(VALUE self, VALUE value) { \
    auto& camera = rb::get<Camera2D>(self);       \
    auto* vec2 = rb::get_safe<Vector2>(value, rb_cVec2);       \
    camera.member = *vec2;                \
    return self;                               \
  }

#define RB_METHOD_CAMERA_GETTER(name, member)   \
  static VALUE name(VALUE self) {        \
    auto& camera = rb::get<Camera2D>(self); \
                                         \
    return DBL2NUM(camera.member);      \
  }

#define RB_METHOD_CAMERA_SETTER(name, member)         \
  static VALUE name(VALUE self, VALUE value) { \
    auto& camera = rb::get<Camera2D>(self);       \
    camera.member = NUM2FLT(value);           \
    return self;                               \
  }

#endif // CAMERA_H
