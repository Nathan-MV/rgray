#pragma once

#include <type_traits>
#include <typeinfo>
#include "graphics/bitmap_bindings.h"
#include "graphics/color_bindings.h"
#include "graphics/font_bindings.h"
#include "graphics/render_texture_bindings.h"
#include "graphics/shader_bindings.h"
#include "graphics/sprite_bindings.h"
#include "math/rect_bindings.h"
#include "math/vec2_bindings.h"
#include "math/vec3_bindings.h"
#include "math/vec4_bindings.h"
#if defined(_WIN32) || defined(_WIN64)
#include "fix_win32_compatibility.h"
#endif
#include <ruby.h>
#include "ruby/encoding.h"
#include "ruby/version.h"

    template <class T>
    auto rb_object_free(void* ptr) { delete static_cast<T *>(ptr); }

template <class T> auto rb_object_alloc(VALUE klass) {
  try {
    T *obj = new T();
    return Data_Wrap_Struct(klass, nullptr, rb_object_free<T>, obj);
  } catch (const std::bad_alloc &e) {
    rb_raise(rb_eNoMemError, "Failed to allocate memory for %s.", typeid(T).name());
    return Qnil;
  }
}

// Convert Ruby array to C int array
static int *get_int_array(VALUE rb_array) {
  if (TYPE(rb_array) != T_ARRAY) {
    rb_raise(rb_eTypeError, "Expected an array");
  }

  long length = RARRAY_LEN(rb_array);
  if (length == 0) {
    return nullptr;  // No need to allocate memory for an empty array
  }

  int *int_array = (int *)malloc(length * sizeof(int));  // Use malloc for heap allocation
  if (int_array == nullptr) {
    rb_raise(rb_eNoMemError, "Failed to allocate memory");
  }

  for (long i = 0; i < length; i++) {
    int_array[i] = NUM2INT(RARRAY_AREF(rb_array, i));  // Use RARRAY_AREF for direct access
  }

  return int_array;  // Safe to return as it's allocated on the heap
}

// Base Ruby method wrappers without result
#define RB_METHOD(name, func)    \
  static auto name(VALUE self) { \
    func();                      \
    return self;                 \
  }
#define RB_METHOD_RESULT(name, func, wrap) \
  static auto name(VALUE self) {           \
    auto res = func();                     \
    return wrap(res);                      \
  }
#define RB_METHOD_RESULT_CONST(name, func, wrap) \
  static auto name(VALUE self) {                 \
    const auto *res = func();                    \
    return wrap(res);                            \
  }

// Macros for a single argument
#define RB_METHOD_ARG(name, func, ret, conv) \
  static auto name(VALUE self, VALUE arg) {  \
    func(conv(arg));                         \
    return ret;                              \
  }
#define RB_METHOD_RESULT_ARG(name, func, wrap, conv) \
  static auto name(VALUE self, VALUE arg) {          \
    auto res = func(conv(arg));                      \
    return wrap(res);                                \
  }
#define RB_METHOD_RESULT_CONST_ARG(name, func, wrap, conv) \
  static auto name(VALUE self, VALUE arg) {                \
    const auto *res = func(conv(arg));                     \
    return wrap(res);                                      \
  }

// Two argument macros
#define RB_METHOD_ARG_2(name, func, ret, conv1, conv2) \
  static auto name(VALUE self, VALUE a1, VALUE a2) {   \
    func(conv1(a1), conv2(a2));                        \
    return ret;                                        \
  }
#define RB_METHOD_RESULT_ARG_2(name, func, wrap, conv1, conv2) \
  static auto name(VALUE self, VALUE a1, VALUE a2) {           \
    auto res = func(conv1(a1), conv2(a2));                     \
    return wrap(res);                                          \
  }

// Three argument macros
#define RB_METHOD_ARG_3(name, func, ret, conv1, conv2, conv3)  \
  static auto name(VALUE self, VALUE a1, VALUE a2, VALUE a3) { \
    func(conv1(a1), conv2(a2), conv3(a3));                     \
    return ret;                                                \
  }
#define RB_METHOD_RESULT_ARG_3(name, func, wrap, conv1, conv2, conv3) \
  static auto name(VALUE self, VALUE a1, VALUE a2, VALUE a3) {        \
    auto res = func(conv1(a1), conv2(a2), conv3(a3));                 \
    return wrap(res);                                                 \
  }

// Four argument macros
#define RB_METHOD_ARG_4(name, func, ret, conv1, conv2, conv3, conv4)     \
  static auto name(VALUE self, VALUE a1, VALUE a2, VALUE a3, VALUE a4) { \
    func(conv1(a1), conv2(a2), conv3(a3), conv4(a4));                    \
    return ret;                                                          \
  }
#define RB_METHOD_RESULT_ARG_4(name, func, wrap, conv1, conv2, conv3, conv4) \
  static auto name(VALUE self, VALUE a1, VALUE a2, VALUE a3, VALUE a4) {     \
    auto res = func(conv1(a1), conv2(a2), conv3(a3), conv4(a4));             \
    return wrap(res);                                                        \
  }

// Normal macros
#define RB_METHOD_INT(name, func) RB_METHOD_RESULT(name, func, INT2NUM)
#define RB_METHOD_FLOAT(name, func) RB_METHOD_RESULT(name, func, DBL2NUM)

// Const macros
#define RB_METHOD_CONST_STR(name, func) RB_METHOD_RESULT_CONST(name, func, rb_str_new_cstr)

// Specific single argument type macros
#define RB_METHOD_ARG_STR(name, func, ret) RB_METHOD_ARG(name, func, ret, StringValueCStr)
#define RB_METHOD_ARG_INT(name, func, ret) RB_METHOD_ARG(name, func, ret, NUM2INT)
#define RB_METHOD_ARG_UINT(name, func, ret) RB_METHOD_ARG(name, func, ret, NUM2UINT)
#define RB_METHOD_ARG_FLOAT(name, func, ret) RB_METHOD_ARG(name, func, ret, NUM2FLT)
#define RB_METHOD_ARG_IMG(name, func, ret) RB_METHOD_ARG(name, func, ret, *get_image)
#define RB_METHOD_INT_ARG(name, func) RB_METHOD_RESULT_ARG(name, func, INT2NUM, NUM2INT)
#define RB_METHOD_INT_ARG_STR(name, func) RB_METHOD_RESULT_ARG(name, func, INT2NUM, StringValueCStr)
#define RB_METHOD_CONST_STR_ARG_INT(name, func) RB_METHOD_RESULT_CONST_ARG(name, func, rb_str_new_cstr, NUM2INT)

// Specific two-argument macros
#define RB_METHOD_ARG_INT_INT(name, func, ret) RB_METHOD_ARG_2(name, func, ret, NUM2INT, NUM2INT)
#define RB_METHOD_ARG_FLOAT_FLOAT(name, func, ret) RB_METHOD_ARG_2(name, func, ret, NUM2FLT, NUM2FLT)
#define RB_METHOD_ARG_IMG_INT(name, func, ret) RB_METHOD_ARG_2(name, func, ret, get_image, NUM2INT)
#define RB_METHOD_INT_ARG_INT_INT(name, func) RB_METHOD_RESULT_ARG_2(name, func, INT2NUM, NUM2INT, NUM2INT)
#define RB_METHOD_FLOAT_ARG_INT_INT(name, func) RB_METHOD_RESULT_ARG_2(name, func, DBL2NUM, NUM2INT, NUM2INT)

// Specific three-argument macros
#define RB_METHOD_ARG_INT_INT_INT(name, func, ret) RB_METHOD_ARG_3(name, func, ret, NUM2INT, NUM2INT, NUM2INT)
#define RB_METHOD_ARG_INT_INT_STR(name, func, ret) RB_METHOD_ARG_3(name, func, ret, NUM2INT, NUM2INT, StringValueCStr)
#define RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT(name, func) RB_METHOD_RESULT_ARG_3(name, func, DBL2NUM, NUM2FLT, NUM2FLT, NUM2FLT)

// Specific four-argument macro
#define RB_METHOD_INT_FLOAT_FLOAT_FLOAT(name, func, ret) RB_METHOD_ARG_4(name, func, ret, NUM2INT, NUM2FLT, NUM2FLT, NUM2FLT)
#define RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT_FLOAT(name, func) RB_METHOD_RESULT_ARG_4(name, func, DBL2NUM, NUM2FLT, NUM2FLT, NUM2FLT, NUM2FLT)
#define RB_METHOD_ARG_INT_FLOAT_FLOAT_FLOAT(name, func, ret) RB_METHOD_ARG_4(name, func, ret, NUM2INT, NUM2FLT, NUM2FLT, NUM2FLT)

// Boolean macros
#define RB_METHOD_BOOL(name, func) \
  static auto name(VALUE self) { return func() ? Qtrue : Qfalse; }
#define RB_METHOD_BOOL_ARG_INT(name, func) \
  static auto name(VALUE self, VALUE val) { return func(NUM2INT(val)) ? Qtrue : Qfalse; }
#define RB_METHOD_BOOL_ARG_INT_INT(name, func) \
  static auto name(VALUE self, VALUE a, VALUE b) { return func(NUM2INT(a), NUM2INT(b)) ? Qtrue : Qfalse; }
#define RB_METHOD_BOOL_ARG_UINT(name, func) \
  static auto name(VALUE self, VALUE val) { return func(NUM2UINT(val)) ? Qtrue : Qfalse; }

// Wrapper for vector objects (example for a Vector2 type)
#define RB_METHOD_TO_VEC2(name, func)              \
  static auto name(VALUE self) {                   \
    auto res = func();                             \
    return rb::alloc_copy<Vector2>(rb_cVec2, res); \
  }
#define RB_METHOD_VEC2_ARG_INT(name, func)         \
  static auto name(VALUE self, VALUE val) {        \
    auto res = func(NUM2INT(val));                 \
    return rb::alloc_copy<Vector2>(rb_cVec2, res); \
  }

// Wrapper for image objects (example for an Image type)
#define RB_METHOD_TO_IMG(name, func)              \
  static auto name(VALUE self) {                  \
    auto res = func();                           \
    return rb::alloc_copy<Image>(rb_cBitmap, res); \
  }
