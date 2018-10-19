
#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>

const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const uint16_t FRAME_RATE = 60;

int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!");

  window.setFramerateLimit(FRAME_RATE);
  
  // Test paddle
  sf::RectangleShape paddle;
  paddle.setSize(sf::Vector2f(20, 100));
  paddle.setPosition(sf::Vector2f(10, 20));
  paddle.setFillColor(sf::Color::Red);
  

  sf::Clock frameclock;
  
  while (window.isOpen()) {
    
    frameclock.restart();
      
    sf::Event event;
    while (window.pollEvent(event)) {
	
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      else if (event.type == sf::Event::KeyPressed) {
	// std::cout << "Key pressed!" << std::endl; 
      }
    }

      
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      paddle.move(sf::Vector2f(0,-5));
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      paddle.move(sf::Vector2f(0,5));
    }
      
      
    window.clear();
    window.draw(paddle);
    window.display();
  }

  return 0;
}
