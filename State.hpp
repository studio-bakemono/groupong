#pragma once

#include <SFML/Graphics.hpp>

class Game;

class State {
public:
  virtual void onEnter(Game *game) = 0;
  virtual void onEvent() = 0;
  virtual State *update(sf::RenderWindow& window) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
  
  
};
