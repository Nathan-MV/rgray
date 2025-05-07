#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include "ruby_values.h"
#include "ruby_adapter.h"
#include "rgray/raylib_values.h"

extern VALUE rb_cBitmap;
extern "C" void Init_Bitmap();

extern "C" inline Image* get_image(VALUE obj) {
  Image *img;
  Data_Get_Struct(obj, Image, img);

  return img;
}

// Free the Image object
// This function is called when the Ruby object is garbage collected
template <class T>
void free_image(void* data) {
	T* ptr = reinterpret_cast<T*>(data);
	UnloadImage(*ptr);
	delete ptr;
}

// Allocates and wraps a new instance of Image
// This function is called when the Ruby object is created
template <class T>
VALUE alloc_image(VALUE klass) {
	return Data_Wrap_Struct(klass, rb::mark<T>, free_image<T>, new T());
}

#endif // BITMAP_H
