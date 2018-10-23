#pragma once

#include <SFML/Graphics.hpp>

#include <cstdint>

class Paddle {
public:
  sf::RectangleShape rect;

  uint16_t score = 0;
  
public:
  // Default colour to cyan, default position to zero. Position is at the end as
  // not to confuse the constuctor with multiple sf::Vector2f values (which it will) 
  explicit Paddle( sf::Vector2f size, sf::Color color = sf::Color::Cyan,
		   sf::Vector2f position = sf::Vector2f(0,0) ) {

    rect.setSize(size);
    rect.setFillColor(color);
    rect.setPosition( position );
    
  }

  virtual void update(sf::RenderWindow& window);
  void render(sf::RenderWindow& window);

  
  inline void setPosition(sf::Vector2f position) {
    rect.setPosition(position);
  }

  inline sf::Vector2f getPosition() {
    return rect.getPosition();
  }

  inline sf::Vector2f getSize() {
    return rect.getSize();
  }

  inline sf::Color getColor() {
    return rect.getFillColor();
  }
  
  inline void setColor(sf::Color color) {
    rect.setFillColor(color);
  }
  
};
