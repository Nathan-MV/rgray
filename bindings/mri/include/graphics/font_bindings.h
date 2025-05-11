#pragma once

#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cFont;
extern "C" void Init_Font();

// Free the Font object
// This function is called when the Ruby object is garbage collected
template <class T> void free_font(void* data) {
  T* ptr = reinterpret_cast<T*>(data);
  UnloadFont(*ptr);
  delete ptr;
}

// Allocates and wraps a new instance of Font
// This function is called when the Ruby object is created
template <class T> VALUE alloc_font(VALUE klass) { return Data_Wrap_Struct(klass, nullptr, free_font<T>, new T()); }
