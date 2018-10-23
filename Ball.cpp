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

void Ball::reset(sf::RenderWindow& window) {
	position.x = (window.getSize().x)/2;
	position.y = (window.getSize().y)/2;
	velocity.x = rand() %7 + (-3);
	velocity.y = rand() %7 + (-3);
}

