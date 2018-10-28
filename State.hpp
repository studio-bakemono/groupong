#pragma once

#include <SFML/Graphics.hpp>

class State {
public:
  virtual void onEnter(sf::RenderWindow& window) = 0;
  virtual void onEvent() = 0;
  virtual void update(sf::RenderWindow& window) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
  
  
};
