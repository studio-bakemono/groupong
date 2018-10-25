#pragma once

#include <SFML/Graphics.hpp>

#include <cstdint>

class Paddle {
public:
  sf::RectangleShape rect;
  sf::Keyboard::Key upKey;
  sf::Keyboard::Key downKey;
  uint16_t score = 0;
  
public:
  Paddle(){}
  // Default colour to cyan, default position to zero. Position is at the end as
  // not to confuse the constuctor with multiple sf::Vector2f values (which it will) 
  explicit Paddle( sf::Vector2f size, sf::Color color = sf::Color::Cyan,
       sf::Keyboard::Key upKey = sf::Keyboard::Tilde,
       sf::Keyboard::Key downKey = sf::Keyboard::Tilde, 
       sf::Vector2f position = sf::Vector2f(0,0)) {

    rect.setSize(size);
    rect.setFillColor(color);
    rect.setPosition( position );
    setUpKey(upKey);
    setDownKey(downKey);
  }

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

  inline void setUpKey(sf::Keyboard::Key key) {
    upKey = key;
  }
  inline void setDownKey(sf::Keyboard::Key key) {
    downKey = key;
  }
  
  virtual void update();
};
