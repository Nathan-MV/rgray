#include <graphics/render_texture_bindings.h>

VALUE rb_cRenderTexture;

// RLAPI RenderTexture2D LoadRenderTexture(int width, int height); // Load texture for rendering
// (framebuffer)
static auto rb_render_texture_initialize(VALUE self, VALUE rb_width, VALUE rb_height) {
  auto& render_texture = rb::get<RenderTexture2D>(self);
  auto width = NUM2INT(rb_width);
  auto height = NUM2INT(rb_height);

  if (width <= 0 || height <= 0) {
    rb_raise(rb_eArgError, "Width and height must be positive integers.");
    return Qnil;
  }

  render_texture = LoadRenderTexture(width, height);

  return self;
}

RB_RENDER_TEXTURE_GETTER_UINT(rb_render_texture_id, id)
RB_RENDER_TEXTURE_GETTER_TEXTURE(rb_render_texture_texture, texture)
RB_RENDER_TEXTURE_GETTER_TEXTURE(rb_render_texture_depth, depth)

// RLAPI bool IsRenderTextureValid(RenderTexture2D target); // Check if a render texture is ready
static auto rb_is_render_texture_ready(VALUE self) {
  auto& render_texture = rb::get<RenderTexture2D>(self);

  auto result = IsRenderTextureValid(render_texture);
  return result ? Qtrue : Qfalse;
}

// RLAPI void UnloadRenderTexture(RenderTexture2D target); // Unload render texture from GPU memory
// (VRAM)
static auto rb_unload_render_texture(VALUE self) {
  auto& render_texture = rb::get<RenderTexture2D>(self);

  UnloadRenderTexture(render_texture);
  rb::raw_dispose<RenderTexture2D>(self);

  return Qnil;
}

// RLAPI void BeginTextureMode(RenderTexture2D target); // Begin drawing to render texture
// RLAPI void EndTextureMode(void);                     // Ends drawing to render texture
static auto rb_begin_texture_mode(VALUE self) {
  auto& render_texture = rb::get<RenderTexture2D>(self);

  if (!rb_block_given_p()) {
    rb_raise(rb_eArgError, "A block is required for `RenderTexture#begin`.");
    return Qnil;
  }

  BeginTextureMode(render_texture);
  rb_yield(Qnil);
  EndTextureMode();

  return Qnil;
}

extern "C" void Init_RenderTexture() {
  rb_cRenderTexture = rb_define_class("RenderTexture", rb_cObject);
  rb_define_alloc_func(rb_cRenderTexture, alloc_render_texture<RenderTexture2D>);

  rb_define_method(rb_cRenderTexture, "initialize", rb_render_texture_initialize, 2);
  rb_define_method(rb_cRenderTexture, "id", rb_render_texture_id, 0);
  rb_define_method(rb_cRenderTexture, "texture", rb_render_texture_texture, 0);
  rb_define_method(rb_cRenderTexture, "depth", rb_render_texture_depth, 0);

  rb_define_method(rb_cRenderTexture, "ready?", rb_is_render_texture_ready, 0);
  rb_define_method(rb_cRenderTexture, "unload", rb_unload_render_texture, 0);

  rb_define_method(rb_cRenderTexture, "begin", rb_begin_texture_mode, 0);
}
