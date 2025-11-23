#include "math/circle_bindings.h"
#include <raylib.h>
#include "ruby_adapter.h"

VALUE rb_cCircle;

static VALUE rb_circle_initialize(VALUE self, VALUE rb_center, VALUE rb_radius) {
  auto& circle = rb::get<Circle>(self);
  auto* center = rb::get_safe<Vector2>(rb_center, rb_cVec2);
  auto radius = NUM2FLT(rb_radius);

  circle.center = *center;
  circle.radius = radius;

  return self;
}

static VALUE rb_get_center(VALUE self) {
  auto& circle = rb::get<Circle>(self);

  return rb::alloc_borrowed<Vector2>(rb_cVec2, &circle.center);
}

static VALUE rb_set_center(VALUE self, VALUE value) {
  auto& circle = rb::get<Circle>(self);
  auto* center = rb::get_safe<Vector2>(value, rb_cVec2);

  circle.center = *center;

  return self;
}

static VALUE rb_get_radius(VALUE self) { return rb::getter<Circle, &Circle::radius, DBL2NUM>(self); }

static VALUE rb_set_radius(VALUE self, VALUE value) { return rb::setter<Circle, &Circle::radius, NUM2DBL>(self, value); }

// RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color);                              // Draw a color-filled circle

// RLAPI void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);      // Draw a piece of a circle
static VALUE rb_draw_circle_sector(VALUE self, VALUE rb_start_angle, VALUE rb_end_angle, VALUE rb_segments, VALUE rb_color) {
  auto& circle = rb::get<Circle>(self);
  auto center = circle.center;
  auto radius = circle.radius;
  auto startAngle = NUM2FLT(rb_start_angle);
  auto endAngle = NUM2FLT(rb_end_angle);
  auto segments = NUM2INT(rb_segments);
  auto* color = rb::get_safe<Color>(rb_color, rb_cColor);

  DrawCircleSector(center, radius, startAngle, endAngle, segments, *color);

  return self;
}
// RLAPI void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color); // Draw circle sector outline
static VALUE rb_draw_circle_sector_lines(VALUE self, VALUE rb_start_angle, VALUE rb_end_angle, VALUE rb_segments, VALUE rb_color) {
  auto& circle = rb::get<Circle>(self);
  auto center = circle.center;
  auto radius = circle.radius;
  auto startAngle = NUM2FLT(rb_start_angle);
  auto endAngle = NUM2FLT(rb_end_angle);
  auto segments = NUM2INT(rb_segments);
  auto* color = rb::get_safe<Color>(rb_color, rb_cColor);

  DrawCircleSectorLines(center, radius, startAngle, endAngle, segments, *color);

  return self;
}
// RLAPI void DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer);         // Draw a gradient-filled circle
static VALUE rb_draw_circle_gradient(VALUE self, VALUE rb_inner, VALUE rb_outer) {
  auto& circle = rb::get<Circle>(self);
  auto center = circle.center;
  auto radius = circle.radius;
  auto* inner = rb::get_safe<Color>(rb_inner, rb_cColor);
  auto* outer = rb::get_safe<Color>(rb_outer, rb_cColor);

  DrawCircleGradient(center.x, center.y, radius, *inner, *outer);

  return self;
}
// RLAPI void DrawCircleV(Vector2 center, float radius, Color color);                                       // Draw a color-filled circle (Vector version)
static VALUE rb_draw_circle(VALUE self, VALUE rb_color) {
  auto& circle = rb::get<Circle>(self);
  auto center = circle.center;
  auto radius = circle.radius;
  auto* color = rb::get_safe<Color>(rb_color, rb_cColor);

  DrawCircleV(center, radius, *color);

  return self;
}
// RLAPI void DrawCircleLines(int centerX, int centerY, float radius, Color color);                         // Draw circle outline

// RLAPI void DrawCircleLinesV(Vector2 center, float radius, Color color);                                  // Draw circle outline (Vector version)
static VALUE rb_draw_circle_lines(VALUE self, VALUE rb_color) {
  auto& circle = rb::get<Circle>(self);
  auto center = circle.center;
  auto radius = circle.radius;
  auto* color = rb::get_safe<Color>(rb_color, rb_cColor);

  DrawCircleLinesV(center, radius, *color);

  return self;
}

// RLAPI bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);        // Check collision between two circles
static VALUE rb_check_collision_circles(VALUE self, VALUE rb_other) {
  auto& circle = rb::get<Circle>(self);
  auto* other = rb::get_safe<Circle>(rb_other, rb_cCircle);

  auto result = CheckCollisionCircles(circle.center, circle.radius, other->center, other->radius);

  return result ? Qtrue : Qfalse;
}
// RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);                         // Check collision between circle and rectangle
static VALUE rb_check_collision_circle_rec(VALUE self, VALUE rb_rec) {
  auto& circle = rb::get<Circle>(self);
  auto* rec = rb::get_safe<Rectangle>(rb_rec, rb_cRect);

  auto result = CheckCollisionCircleRec(circle.center, circle.radius, *rec);

  return result ? Qtrue : Qfalse;
}
// RLAPI bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);                       // Check if point is inside circle
static VALUE rb_check_collision_point_circle(VALUE self, VALUE rb_point) {
  auto& circle = rb::get<Circle>(self);
  auto* point = rb::get_safe<Vector2>(rb_point, rb_cVec2);

  auto result = CheckCollisionPointCircle(*point, circle.center, circle.radius);

  return result ? Qtrue : Qfalse;
}
// RLAPI bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2);               // Check if circle collides with a line created betweeen two points [p1] and [p2]
static VALUE rb_check_collision_circle_line(VALUE self, VALUE rb_p1, VALUE rb_p2) {
  auto& circle = rb::get<Circle>(self);
  auto* p1 = rb::get_safe<Vector2>(rb_p1, rb_cVec2);
  auto* p2 = rb::get_safe<Vector2>(rb_p2, rb_cVec2);

  auto result = CheckCollisionCircleLine(circle.center, circle.radius, *p1, *p2);

  return result ? Qtrue : Qfalse;
}

extern "C" void Init_Circle() {
  rb_cCircle = rb_define_class("Circle", rb_cObject);
  rb_define_alloc_func(rb_cCircle, rb::alloc<Circle>);

  rb_define_method(rb_cCircle, "initialize", rb_circle_initialize, 2);
  rb_define_method(rb_cCircle, "center", rb_get_center, 0);
  rb_define_method(rb_cCircle, "center=", rb_set_center, 1);
  rb_define_method(rb_cCircle, "radius", rb_get_radius, 0);
  rb_define_method(rb_cCircle, "radius=", rb_set_radius, 1);

  rb_define_method(rb_cCircle, "draw_sector", rb_draw_circle_sector, 4);
  rb_define_method(rb_cCircle, "draw_sector_lines", rb_draw_circle_sector_lines, 4);
  rb_define_method(rb_cCircle, "draw_gradient", rb_draw_circle_gradient, 2);
  rb_define_method(rb_cCircle, "draw", rb_draw_circle, 1);
  rb_define_method(rb_cCircle, "draw_lines", rb_draw_circle_lines, 1);
  rb_define_method(rb_cCircle, "collides?", rb_check_collision_circles, 1);
  rb_define_method(rb_cCircle, "collides_rec?", rb_check_collision_circle_rec, 1);
  rb_define_method(rb_cCircle, "collides_point?", rb_check_collision_point_circle, 1);
  rb_define_method(rb_cCircle, "collides_line?", rb_check_collision_circle_line, 2);

  // rb_define_method(rb_cCircle, "to_s", rb::to_s<Circle>, 0);
  // rb_define_method(rb_cCircle, "inspect", rb::inspect<Circle>, 0);
}
