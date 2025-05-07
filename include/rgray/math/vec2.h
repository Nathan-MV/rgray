#ifndef VEC2_H
#define VEC2_H

#pragma once

#include <string>
#include "raylib.h"

Vector2 Vector2DivideValue(Vector2 vector, float divisor);
Vector2 Vector2RandomMovement(Vector2 &position, float speed, const std::string &direction);
bool Vector2IsZero(const Vector2 &vector);
std::string Vector2ToString(const Vector2 &vector);

#endif  // VEC2_H
