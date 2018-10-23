
#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>
#include <string>


#include "Paddle.hpp"
#include "PlayerPaddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include "AIPaddle.hpp"
const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const uint16_t FRAME_RATE = 60;


int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!");
  window.setFramerateLimit(FRAME_RATE);

  // Load the font used in the game
  sf::Font font;
  if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    std::cout << "Error loading font\n";
  }

  // Pass font along to scoreboard
  Scoreboard scoreboard(window, font);
  
  
  // Set up paddles:
  // Each paddle's position is set seperately from constructor since it's position is
  // dependent on it's own size, which is set in the constructor.

  PlayerPaddle playerPaddle( sf::Vector2f(20, 100),
			     sf::Color::Red
			     );
  
  playerPaddle.setPosition(sf::Vector2f( 20, (WINDOW_HEIGHT/2 - (playerPaddle.getSize().y/2)) ));
  
  AIPaddle AIpaddle ( sf::Vector2f(20, 100),
		    sf::Color::Blue
		    );
  
  AIpaddle.setPosition( sf::Vector2f(WINDOW_WIDTH - (20+AIpaddle.getSize().x),
				     WINDOW_HEIGHT/2 - (AIpaddle.getSize().y/2) ));



  Ball ball(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
  
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
  

    // Update 
    
    playerPaddle.update(window);
    AIpaddle.update(window);

    // Colision detection
    if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider) ||
        AIpaddle.rect.getGlobalBounds().intersects(ball.collider)) {
      //unsure exactly how velocity will change, fix this later
      ball.velocity.x *= -1; 
      ball.velocity.y *= -1;
    }
    if (ball.collider.top < 0 || ball.collider.top + ball.collider.height
     > WINDOW_HEIGHT) {
      ball.velocity.y *= -1;
    }

    ball.update(window);
    
    //Score update
    if(ball.collider.left + ball.collider.width > WINDOW_WIDTH) {
      scoreboard.updateScore(0);
      //should resetting it be a function inside ball?
      ball.position.x = WINDOW_WIDTH/2;
      ball.position.y = WINDOW_HEIGHT/2;
      ball.velocity.x = 3;
      ball.velocity.y = 3;
    }
    if(ball.collider.left  < 0) {
      scoreboard.updateScore(1);
      ball.position.x = WINDOW_WIDTH/2;
      ball.position.y = WINDOW_HEIGHT/2;
      ball.velocity.x = 3;
      ball.velocity.y = 3;
    }

    // Render
    window.clear();
    
    playerPaddle.render(window);
    AIpaddle.render(window);
    
    ball.render(window);
    scoreboard.render(window);
    
    window.display();
  }

  return 0;
}
