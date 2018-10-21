
#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>


#include "Paddle.hpp"
#include "PlayerPaddle.hpp"

const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const uint16_t FRAME_RATE = 60;

int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!");

  window.setFramerateLimit(FRAME_RATE);


  // Set up paddles:
  // Each paddle's position is set seperately from constructor since it's position is
  // dependent on it's own size, which is set in the constructor.

  PlayerPaddle playerPaddle( sf::Vector2f(20, 100),
			     sf::Color::Red
			     );
  playerPaddle.setPosition(sf::Vector2f( 20, (WINDOW_HEIGHT/2 - (playerPaddle.getSize().y/2)) ));
  
  Paddle AIpaddle ( sf::Vector2f(20, 100),
		    sf::Color::Blue
		    );
  AIpaddle.setPosition( sf::Vector2f(WINDOW_WIDTH - (20+AIpaddle.getSize().x),
				     WINDOW_HEIGHT/2 - (AIpaddle.getSize().y/2) ));


  
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
