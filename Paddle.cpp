#include "Paddle.hpp"

void Paddle::update(sf::RenderWindow& window) {
  //only move if paddle will stay on screen
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
      rect.getPosition().y > 0) {
    rect.move(sf::Vector2f(0,-5));
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
      rect.getPosition().y < window.getSize().y - rect.getSize().y) {
    rect.move(sf::Vector2f(0,5));
  }
}

void Paddle::render(sf::RenderWindow& window) {
  window.draw(rect);
}
