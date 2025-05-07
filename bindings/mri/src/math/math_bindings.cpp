#include "math/math_bindings.h"
#include "ruby_values.h"
#include "ruby_adapter.h"

// Binding to Clamp(float, float, float)
RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT(rb_math_clamp, Clamp)

//Binding to Lerp(float, float, float)
RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT(rb_math_lerp, Lerp)

// Binding to Normalize(float, float, float)
RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT(rb_math_normalize, Normalize)

// Binding to Remap(float, float, float, float, float)
static VALUE rb_math_remap(VALUE self, VALUE value, VALUE in_start, VALUE in_end, VALUE out_start,
                           VALUE out_end) {
  auto result = Remap(NUM2FLT(value), NUM2FLT(in_start), NUM2FLT(in_end),
                       NUM2FLT(out_start), NUM2FLT(out_end));

  return DBL2NUM(result);
}

// Binding to Wrap(float, float, float)
RB_METHOD_FLOAT_ARG_FLOAT_FLOAT_FLOAT(rb_math_wrap, Wrap)

// Binding to FloatEquals(float, float)
static VALUE rb_math_float_equals(VALUE self, VALUE x, VALUE y) {
  auto result = FloatEquals(NUM2FLT(x), NUM2FLT(y));

  return result ? Qtrue : Qfalse;
}

// Initialization function
extern "C" void Init_Math() {
  rb_define_module_function(rb_mMath, "clamp", rb_math_clamp, 3);
  rb_define_module_function(rb_mMath, "lerp", rb_math_lerp, 3);
  rb_define_module_function(rb_mMath, "normalize", rb_math_normalize, 3);
  rb_define_module_function(rb_mMath, "remap", rb_math_remap, 5);
  rb_define_module_function(rb_mMath, "wrap", rb_math_wrap, 3);
  rb_define_module_function(rb_mMath, "float_equals", rb_math_float_equals, 2);
}
