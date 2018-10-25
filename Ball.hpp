#pragma once

#include <SFML/Graphics.hpp>


class Ball {

public:

  sf::Vector2f position;
  
  sf::CircleShape circle;
  sf::FloatRect collider;

  sf::Vector2f velocity;
  
public:

  Ball(sf::Vector2f position = sf::Vector2f(0,0), int radius = 30, 
    sf::Vector2f velocity = sf::Vector2f(-2,-2)):
    position(position),
    velocity(velocity)
  {
    circle.setRadius(radius);
    collider = sf::FloatRect(position, sf::Vector2f(2*radius, 2*radius));
  }
  
  
  void update();
  void render(sf::RenderWindow& window);
  void reset();
};
