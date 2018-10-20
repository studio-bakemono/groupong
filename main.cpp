
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
  
  // Player paddle
  sf::RectangleShape playerPaddle;
  playerPaddle.setSize(sf::Vector2f(20, 100));
  playerPaddle.setPosition(sf::Vector2f(10, 20));
  playerPaddle.setFillColor(sf::Color::Red);

  
  sf::RectangleShape AiPaddle;
  AiPaddle.setSize(sf::Vector2f(20, 100));
  // Set AiPaddle in the middle of it's range
  AiPaddle.setPosition(sf::Vector2f(WINDOW_WIDTH - (10+AiPaddle.getSize().x), WINDOW_HEIGHT/2 -(AiPaddle.getSize().y/2)) );
  AiPaddle.setFillColor(sf::Color::Red);
  
  
  while (window.isOpen()) {
      
    sf::Event event;
    while (window.pollEvent(event)) {
	
      if (event.type == sf::Event::Closed) {
	window.close();
      }
      else if (event.type == sf::Event::KeyPressed) {
	// std::cout << "Key pressed!" << std::endl; 
      }
    }

    // Update logic goes here. The reason why is that if we make these update calls
    // inside the pollEvent loop it will not create smooth movement/updating.
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      playerPaddle.move(sf::Vector2f(0,-5));
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      playerPaddle.move(sf::Vector2f(0,5));
    }
      
      
    window.clear();
    window.draw(playerPaddle);
    window.draw(AiPaddle);
    window.display();
  }

  return 0;
}
