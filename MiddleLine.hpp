#pragma once

#include <SFML/Graphics.hpp>

class MiddleLine {
public:
  static const int LINE_COUNT = 16;
  sf::RectangleShape lines[LINE_COUNT];

public:

  MiddleLine() {}
  
  MiddleLine(sf::RenderWindow& window) {
    int x = window.getSize().x;
    int y = window.getSize().y;

    for (int i = 0; i < LINE_COUNT; i++ ) { 
      lines[i] = sf::RectangleShape(sf::Vector2f(4, 24));
      lines[i].setFillColor(sf::Color::White);
      lines[i].setPosition(float(x / 2), float(i * 30 + 60));
    }
  }

  ~MiddleLine() {}
  
  void render(sf::RenderWindow& window);
};
