#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cVec4;
extern "C" void Init_Vec4();

inline Vector4* get_vec4(VALUE obj) {
  Vector4* vec4;
  Data_Get_Struct(obj, Vector4, vec4);

  return vec4;
}
