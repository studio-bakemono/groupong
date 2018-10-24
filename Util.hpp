#pragma once

#include <SFML/Graphics.hpp>

#include <cmath>

static inline void normalizeVec2f(sf::Vector2f& vec) {
  float length = sqrt( (vec.x*vec.x) + (vec.y*vec.y) );
  if (length != 0) {
    vec.x /= length;
    vec.y /= length;
  }
}
