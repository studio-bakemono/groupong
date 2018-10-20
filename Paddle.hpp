#pragma once

#include <SFML/Graphics.hpp>

enum Side {
  LEFT = 0,
  RIGHT = 1
};

class Paddle {
private:
  sf::RectangleShape rect;

public:

  Paddle( int WINDOW_WIDTH, int WINDOW_HEIGHT, Side side, sf::Vector2f size, sf::Color color = sf::Color::Cyan ) {
    rect.setSize(size);
    rect.setFillColor(color);

    if (side == Side::LEFT)
      rect.setPosition( 10, WINDOW_HEIGHT/2 - (rect.getSize().y/2) );
    else if ( side == Side::RIGHT )
      rect.setPosition( WINDOW_WIDTH - (10+rect.getSize().x), WINDOW_HEIGHT/2 - (rect.getSize().y/2) );
    
  }
  
  void update(sf::RenderWindow& window);
  void render(sf::RenderWindow& window);
  
};
