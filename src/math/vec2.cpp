#include "rgray/math/vec2.h"
#include <cstdio>
#include <string>
#include "raylib.h"
#include "raymath.h"
#include "rgray/system/kernel.h"

Vector2 Vector2DivideValue(Vector2 vector, float divisor) {
  return {vector.x / divisor, vector.y / divisor};
}

Vector2 Vector2RandomMovement(Vector2 &position, float speed, const std::string &direction) {
  Vector2 randomDirection = {GetRandomFloat(-1.0F, 1.0F), GetRandomFloat(-1.0F, 1.0F)};

  if (direction == "up") {
    randomDirection.y = GetRandomFloat(-1.0F, 0.0F);
  } else if (direction == "down") {
    randomDirection.y = GetRandomFloat(0.0F, 1.0F);
  } else if (direction == "right") {
    randomDirection.x = GetRandomFloat(0.0F, 1.0F);
  } else if (direction == "left") {
    randomDirection.x = GetRandomFloat(-1.0F, 0.0F);
  }

  const Vector2 velocity = Vector2Scale(randomDirection, speed);
  const Vector2 deltaVelocity = Vector2Scale(velocity, GetFrameTime());
  Vector2 newPosition = Vector2Add(position, deltaVelocity);

  newPosition.x = Clamp(newPosition.x, 0.0F, static_cast<float>(GetScreenWidth()));
  newPosition.y = Clamp(newPosition.y, 0.0F, static_cast<float>(GetScreenHeight()));

  return newPosition;
}

bool Vector2IsZero(const Vector2 &vector) { return (vector.x == 0.0F && vector.y == 0.0F); }

std::string Vector2ToString(const Vector2 &vector) {
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "Vec2(x: %.2f, y: %.2f)", vector.x, vector.y);
  return {buffer};
}
