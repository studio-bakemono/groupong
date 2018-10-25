#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class AIPaddle : public Paddle {
public:
  // Inheret Paddle's constructor
  using Paddle::Paddle;
  
  void update() override {
    //only move if paddle will stay on screen
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
	rect.getPosition().y > 0) {
      rect.move(sf::Vector2f(0,-5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
	rect.getPosition().y < WINDOW_HEIGHT - rect.getSize().y) {
      rect.move(sf::Vector2f(0,5));
    }
  }

   
}; 
