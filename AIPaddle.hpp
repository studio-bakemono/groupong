#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class AIPaddle : public Paddle {
public:
  // Inheret Paddle's constructor
  using Paddle::Paddle;
  
  void update(sf::RenderWindow& window, float frametime) override {
    //only move if paddle will stay on screen
    float dist = 300*frametime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
	rect.getPosition().y > 0) {
      rect.move(sf::Vector2f(0,-dist));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
	rect.getPosition().y < window.getSize().y - rect.getSize().y) {
      rect.move(sf::Vector2f(0,dist));
    }
  }

   
}; 
