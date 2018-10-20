
#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>


#include "Paddle.hpp"

const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const uint16_t FRAME_RATE = 60;

int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!");

  window.setFramerateLimit(FRAME_RATE);


  Paddle playerPaddle( WINDOW_WIDTH, WINDOW_HEIGHT,
		       Side::LEFT,
		       sf::Vector2f(20, 100),
		       sf::Color::Red );

  Paddle AIpaddle ( WINDOW_WIDTH, WINDOW_HEIGHT,
		    Side::RIGHT,
		    sf::Vector2f(20, 100),
		    sf::Color::Blue );


  
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
  

    playerPaddle.update(window);
    AIpaddle.update(window);

    
    window.clear();
    playerPaddle.render(window);
    AIpaddle.render(window);
    window.display();
  }

  return 0;
}
