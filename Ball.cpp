#include "Ball.hpp"
#include "config.hpp"

void Ball::update() {

  position += velocity;

  
  circle.setPosition(position);
  
  collider.left = position.x;
  collider.top = position.y;

}

void Ball::render(sf::RenderWindow& window) {
  window.draw(circle);
}

void Ball::reset() {
	//Want to have the ball only have specific speeds (Not zero)
	static int table[] = {-3, -2, -1, 1, 2, 3};
	position.x = WINDOW_WIDTH/2;
	position.y = WINDOW_HEIGHT/2;
	velocity.x = table[rand() %(sizeof table/ sizeof *table)];
	velocity.y = table[rand() %(sizeof table/ sizeof *table)];
}

