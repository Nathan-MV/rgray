#pragma once

#include <stdio.h>
#include "rgray/raylib_values.h"
#include "ruby_adapter.h"
#include "ruby_values.h"

extern VALUE rb_cSprite;
extern "C" void Init_Sprite();

// Creates a full Ruby-managed copy of a Texture2D (heap allocated, freed with GC)
inline VALUE wrap_texture_copy(const Texture2D& source) {
  Texture2D* copy = ALLOC(Texture2D);
  *copy = source;
  return Data_Wrap_Struct(rb_cSprite, nullptr, nullptr, copy);
}

// Wraps a borrowed pointer to Texture2D (no copy, no free — lifetime managed elsewhere)
inline VALUE wrap_texture_borrowed(Texture2D* tex) { return Data_Wrap_Struct(rb_cSprite, nullptr, nullptr, tex); }

template <typename T> void rb_texture_free(void* ptr) {
  T* obj = static_cast<T*>(ptr);

  UnloadTexture(*obj);
  delete obj;
}

template <typename T> VALUE rb_texture_alloc(VALUE klass) {
  try {
    T* obj = new T();

    return Data_Wrap_Struct(klass, nullptr, rb_texture_free<T>, obj);
  } catch (const std::bad_alloc& e) {
    rb_raise(rb_eNoMemError, "Failed to allocate memory for %s.", typeid(T).name());

    return Qnil;
  }
}

// Macro to define getter methods
#define RB_METHOD_TEXTURE_GETTER_INT(name, member) \
  static VALUE name(VALUE self) {                  \
    auto& texture = rb::get<Texture2D>(self);      \
    return INT2NUM(texture.member);                \
  }
