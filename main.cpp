
#include <SFML/Graphics.hpp>

#include <cstdint>
#include <iostream>
#include <string>


#include "Paddle.hpp"
#include "PlayerPaddle.hpp"

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

  // Player 1 attributes
  int score_player_1 = 0;
  sf::Color color_player_1 = sf::Color::Red;
  sf::Text score_text_player_1;
  score_text_player_1.setPosition(WINDOW_WIDTH / 4, 10);
  score_text_player_1.setFont(font);
  score_text_player_1.setFillColor(color_player_1);
  score_text_player_1.setCharacterSize(48); // in pixels, not points!
  score_text_player_1.setString(std::to_string(score_player_1));

  // Player 2 / AI attributes
  int score_player_2 = 0;
  sf::Color color_player_2 = sf::Color::Blue;
  sf::Text score_text_player_2;
  score_text_player_2.setPosition(WINDOW_WIDTH - WINDOW_WIDTH / 4, 10);
  score_text_player_2.setFont(font);
  score_text_player_2.setFillColor(color_player_2);
  score_text_player_2.setCharacterSize(48); // in pixels, not points!
  score_text_player_2.setString(std::to_string(score_player_2));

  // Set up paddles:
  // Each paddle's position is set seperately from constructor since it's position is
  // dependent on it's own size, which is set in the constructor.

  PlayerPaddle playerPaddle( sf::Vector2f(20, 100),
			     color_player_1
			     );
  playerPaddle.setPosition(sf::Vector2f( 20, (WINDOW_HEIGHT/2 - (playerPaddle.getSize().y/2)) ));
  
  Paddle AIpaddle ( sf::Vector2f(20, 100),
		    color_player_2
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
    window.draw(score_text_player_1);
    window.draw(score_text_player_2);

    window.display();
  }

  return 0;
}
