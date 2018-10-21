#include "Ball.hpp"


void Ball::update(sf::RenderWindow& window) {

  position += velocity;

  
  circle.setPosition(position);
  
  collider.left = position.x;
  collider.top = position.y;
  
}

void Ball::render(sf::RenderWindow& window) {
  window.draw(circle);
}
