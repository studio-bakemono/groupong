#pragma once

#include <SFML/Graphics.hpp>


class Ball {

public:

  sf::Vector2f position;
  
  sf::CircleShape circle;
  sf::FloatRect collider;

  float speed;
  
public:

  Ball(sf::Vector2f position = sf::Vector2f(0,0), int radius = 30, float speed = 2):
    position(position),
    speed(speed)
  {
    circle.setRadius(radius);
    collider = sf::FloatRect(position, sf::Vector2f(radius, radius));
  }
  
  
  void update(sf::RenderWindow& window);
  void render(sf::RenderWindow& window);
  
};
