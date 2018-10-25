#include "Paddle.hpp"
#include "config.hpp"

void Paddle::update() {
  //only move if paddle will stay on screen
  if (sf::Keyboard::isKeyPressed(upKey) && 
	rect.getPosition().y > 0) {
      rect.move(sf::Vector2f(0,-5));
  }
  if (sf::Keyboard::isKeyPressed(downKey) &&
	rect.getPosition().y < WINDOW_HEIGHT - rect.getSize().y) {
      rect.move(sf::Vector2f(0,5));
  }
}
void Paddle::render(sf::RenderWindow& window) {
  window.draw(rect);
}
