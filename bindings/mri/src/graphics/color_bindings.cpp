#include "graphics/color_bindings.h"
#include "ruby/internal/core/rdata.h"

VALUE rb_cColor;

// Get Color structure from hexadecimal value
static auto rb_color_initialize(int argc, VALUE* argv, VALUE self) {
  auto& color = rb::get<Color>(self);

  switch (argc) {
    case 0:
      // Default to black (0, 0, 0, 255)
      color.r = 0;
      color.g = 0;
      color.b = 0;
      color.a = 255;
      break;

    case 1: {
      const auto arg = argv[0];

      // Handle hex string or number
      if (RB_TYPE_P(arg, T_STRING) || RB_TYPE_P(arg, T_FIXNUM) || RB_TYPE_P(arg, T_BIGNUM)) {
        const auto* hex_str = StringValueCStr(argv[0]);
        color = ColorFromHex(hex_str);
        // Handle specified Color object
      } else if (rb_obj_is_kind_of(arg, rb_cColor)) {
        color = *rb::get_safe<Color>(arg, rb_cColor);
      } else {
        rb_raise(rb_eTypeError, "Expected a hex string, number, or Color object.");
      }
      break;
    }

    default: {
      VALUE red, green, blue, alpha;
      rb_scan_args(argc, argv, "31", &red, &green, &blue, &alpha);

      color.r = NUM2INT(red);
      color.g = NUM2INT(green);
      color.b = NUM2INT(blue);
      color.a = NIL_P(alpha) ? 255 : NUM2INT(alpha);  // Default alpha to 255
      break;
    }
  }

  return self;
}

RB_METHOD_COLOR_GETTER(rb_color_get_red, r)
RB_METHOD_COLOR_GETTER(rb_color_get_green, g)
RB_METHOD_COLOR_GETTER(rb_color_get_blue, b)
RB_METHOD_COLOR_GETTER(rb_color_get_alpha, a)
RB_METHOD_COLOR_SETTER(rb_color_set_red, r)
RB_METHOD_COLOR_SETTER(rb_color_set_green, g)
RB_METHOD_COLOR_SETTER(rb_color_set_blue, b)
RB_METHOD_COLOR_SETTER(rb_color_set_alpha, a)

// Color/pixel related functions
// RLAPI bool ColorIsEqual(Color col1, Color col2);                            // Check if two colors are equal
static auto rb_color_is_equal(VALUE self, VALUE rb_other) {
  auto& color = rb::get<Color>(self);
  auto* other = rb::get_safe<Color>(rb_other, rb_cColor);

  auto result = ColorIsEqual(color, *other);

  return result ? Qtrue : Qfalse;
}
// RLAPI Color Fade(Color color, float alpha);                                 // Get color with alpha applied, alpha goes from 0.0f to 1.0f
static auto rb_color_fade(VALUE self, VALUE rb_alpha) {
  auto& color = rb::get<Color>(self);
  auto alpha = NUM2FLT(rb_alpha);

  auto result = Fade(color, alpha);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI int ColorToInt(Color color);                                          // Get hexadecimal value for a Color (0xRRGGBBAA)
static auto rb_color_to_int(VALUE self) {
  auto& color = rb::get<Color>(self);

  auto result = ColorToInt(color);

  return INT2NUM(result);
}
// RLAPI Color ColorFromNormalized(Vector4 normalized);                        // Get Color from normalized values [0..1]
static auto rb_color_normalize(VALUE self) {
  auto& color = rb::get<Color>(self);

  auto result = ColorNormalize(color);

  return rb::alloc_copy<Vector4>(rb_cVec4, result);
}
// RLAPI Vector3 ColorToHSV(Color color);                                      // Get HSV values for a Color, hue [0..360], saturation/value [0..1]
static auto rb_color_to_hsv(VALUE self) {
  auto& color = rb::get<Color>(self);

  auto result = ColorToHSV(color);

  return rb::alloc_copy<Vector3>(rb_cVec3, result);
}
// RLAPI Color ColorTint(Color color, Color tint);                             // Get color multiplied with another color
static auto rb_color_tint(VALUE self, VALUE rb_tint) {
  auto& color = rb::get<Color>(self);
  auto* tint = rb::get_safe<Color>(rb_tint, rb_cColor);

  auto result = ColorTint(color, *tint);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI Color ColorBrightness(Color color, float factor);                     // Get color with brightness correction, brightness factor goes from -1.0f to 1.0f
static auto rb_color_brightness(VALUE self, VALUE rb_factor) {
  auto& color = rb::get<Color>(self);
  auto factor = NUM2FLT(rb_factor);

  auto result = ColorBrightness(color, factor);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI Color ColorContrast(Color color, float contrast);                     // Get color with contrast correction, contrast values between -1.0f and 1.0f
static auto rb_color_contrast(VALUE self, VALUE rb_contrast) {
  auto& color = rb::get<Color>(self);
  auto contrast = NUM2FLT(rb_contrast);

  auto result = ColorContrast(color, contrast);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI Color ColorAlphaBlend(Color dst, Color src, Color tint);              // Get src alpha-blended into dst color with tint
static auto rb_color_alpha_blend(VALUE self, VALUE rb_src, VALUE rb_tint) {
  auto& color = rb::get<Color>(self);
  auto* src = rb::get_safe<Color>(rb_src, rb_cColor);
  auto* tint = rb::get_safe<Color>(rb_tint, rb_cColor);

  auto result = ColorAlphaBlend(color, *src, *tint);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI Color ColorLerp(Color color1, Color color2, float d);                 // Mix 2 Colors Together
static auto rb_color_lerp(VALUE self, VALUE rb_other, VALUE rb_d) {
  auto& color = rb::get<Color>(self);
  auto* other = rb::get_safe<Color>(rb_other, rb_cColor);
  auto d = NUM2FLT(rb_d);

  auto result = ColorLerp(color, *other, d);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI Color GetPixelColor(void *srcPtr, int format);                        // Get Color from a source pixel pointer of certain format
static auto rb_get_pixel_color(VALUE self, VALUE rb_src_ptr, VALUE rb_format) {
  auto* src_ptr = (void*)(uintptr_t)NUM2ULONG(rb_src_ptr);
  auto format = NUM2INT(rb_format);

  auto result = GetPixelColor(src_ptr, format);

  return rb::alloc_copy<Color>(rb_cColor, result);
}
// RLAPI void SetPixelColor(void *dstPtr, Color color, int format);            // Set color formatted into destination pixel pointer
static auto rb_set_pixel_color(VALUE self, VALUE rb_dst_ptr, VALUE rb_color, VALUE rb_format) {
  auto* dst_ptr = (void*)(uintptr_t)NUM2ULONG(rb_dst_ptr);
  auto* color = rb::get_safe<Color>(rb_color, rb_cColor);
  auto format = NUM2INT(rb_format);

  SetPixelColor(dst_ptr, *color, format);

  return self;
}
// RLAPI int GetPixelDataSize(int width, int height, int format);              // Get pixel data size in bytes for certain format
static auto rb_get_pixel_data_size(VALUE self, VALUE rb_width, VALUE rb_height, VALUE rb_format) {
  auto width = NUM2INT(rb_width);
  auto height = NUM2INT(rb_height);
  auto format = NUM2INT(rb_format);

  auto size = GetPixelDataSize(width, height, format);

  return INT2NUM(size);
}
// RLAPI float ColorGetLuminance(Color color);              // Compute relative luminance in linear space from a Color
static VALUE rb_color_get_luminance(VALUE self) {
  auto& color = rb::get<Color>(self);

  auto luminance = ColorGetLuminance(color);

  return DBL2NUM(luminance);
}

extern "C" void Init_Color() {
  rb_cColor = rb_define_class("Color", rb_cObject);
  rb_define_alloc_func(rb_cColor, rb::alloc<Color>);

  // Define initialize and attribute accessors (getters and setters)
  rb_define_method(rb_cColor, "initialize", rb_color_initialize, -1);
  rb_define_method(rb_cColor, "r", rb_color_get_red, 0);
  rb_define_method(rb_cColor, "red", rb_color_get_red, 0);  // r alias
  rb_define_method(rb_cColor, "g", rb_color_get_green, 0);
  rb_define_method(rb_cColor, "green", rb_color_get_green, 0);  // g alias
  rb_define_method(rb_cColor, "b", rb_color_get_blue, 0);
  rb_define_method(rb_cColor, "blue", rb_color_get_blue, 0);  // b alias
  rb_define_method(rb_cColor, "a", rb_color_get_alpha, 0);
  rb_define_method(rb_cColor, "alpha", rb_color_get_alpha, 0);  // a alias
  rb_define_method(rb_cColor, "r=", rb_color_set_red, 1);
  rb_define_method(rb_cColor, "red=", rb_color_set_red, 1);  // r= alias
  rb_define_method(rb_cColor, "g=", rb_color_set_green, 1);
  rb_define_method(rb_cColor, "green=", rb_color_set_green, 1);  // g= alias
  rb_define_method(rb_cColor, "b=", rb_color_set_blue, 1);
  rb_define_method(rb_cColor, "blue=", rb_color_set_blue, 1);  // b= alias
  rb_define_method(rb_cColor, "a=", rb_color_set_alpha, 1);
  rb_define_method(rb_cColor, "alpha=", rb_color_set_alpha, 1);  // a= alias

  // Define additional methods
  rb_define_method(rb_cColor, "eql?", rb_color_is_equal, 1);
  rb_define_method(rb_cColor, "fade", rb_color_fade, 1);
  rb_define_method(rb_cColor, "to_int", rb_color_to_int, 0);
  rb_define_method(rb_cColor, "normalize", rb_color_normalize, 0);
  rb_define_method(rb_cColor, "to_hsv", rb_color_to_hsv, 0);
  rb_define_method(rb_cColor, "tint", rb_color_tint, 1);
  rb_define_method(rb_cColor, "brightness", rb_color_brightness, 1);
  rb_define_method(rb_cColor, "contrast", rb_color_contrast, 1);
  rb_define_method(rb_cColor, "alpha_blend", rb_color_alpha_blend, 2);
  rb_define_method(rb_cColor, "blend", rb_color_alpha_blend, 2);  // alpha_blend alias
  rb_define_method(rb_cColor, "lerp", rb_color_lerp, 2);
  rb_define_method(rb_cColor, "pixel_color", rb_get_pixel_color, 2);
  rb_define_method(rb_cColor, "set_pixel_color", rb_set_pixel_color, 3);
  rb_define_method(rb_cColor, "pixel_data_size", rb_get_pixel_data_size, 3);

  rb_define_method(rb_cColor, "luminance", rb_color_get_luminance, 0);
}
