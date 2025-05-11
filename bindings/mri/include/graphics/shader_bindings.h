#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cShader;
extern "C" void Init_Shader();

// Free the Shader object
// This function is called when the Ruby object is garbage collected
template <class T> void free_shader(void* data) {
  T* ptr = reinterpret_cast<T*>(data);
  UnloadShader(*ptr);
  delete ptr;
}

// Allocates and wraps a new instance of Shader
// This function is called when the Ruby object is created
template <class T> VALUE alloc_shader(VALUE klass) { return Data_Wrap_Struct(klass, nullptr, free_shader<T>, new T()); }
