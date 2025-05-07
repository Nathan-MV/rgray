#ifndef RENDER_TEXTURE_H
#define RENDER_TEXTURE_H

#include "graphics/sprite_bindings.h"
#include "rgray/raylib_values.h"
#include "ruby_values.h"
#include "ruby_adapter.h"

extern VALUE rb_cRenderTexture;
extern "C" void Init_RenderTexture();

// Free the RenderTexture2D object
// This function is called when the Ruby object is garbage collected
template <class T>
void free_render_texture(void* data) {
	T* ptr = reinterpret_cast<T*>(data);
	UnloadRenderTexture(*ptr);
	delete ptr;
}

// Allocates and wraps a new instance of RenderTexture2D
// This function is called when the Ruby object is created
template <class T>
VALUE alloc_render_texture(VALUE klass) {
	return Data_Wrap_Struct(klass, rb::mark<T>, free_render_texture<T>, new T());
}

// Macro to define getter methods
#define RB_RENDER_TEXTURE_GETTER_UINT(name, member)             \
  static VALUE name(VALUE self) {                               \
    auto& render_texture = rb::get<RenderTexture2D>(self);            \
    return UINT2NUM(render_texture.member);                    \
  }

#define RB_RENDER_TEXTURE_GETTER_TEXTURE(name, member)          \
  static VALUE name(VALUE self) {                               \
    auto& render_texture = rb::get<RenderTexture2D>(self);            \
    return rb::alloc_borrowed<Texture2D>(rb_cSprite, &render_texture.member); \
  }

#endif  // RENDER_TEXTURE_H
