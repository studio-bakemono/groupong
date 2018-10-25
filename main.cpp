/*
  Studio Bakemono, 2018
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <iostream>
#include <string>


#include "Util.hpp"
#include "config.hpp"
#include "Game.hpp"

int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!", sf::Style::Default, sf::ContextSettings(0, 0, 8));
  window.setFramerateLimit(FRAME_RATE);

  // Load the font used in the game
  sf::Font font;
  if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    std::cout << "Error loading font\n";
    return -1;
  }
  
  Game game(window, font);
  
  while ( window.isOpen() ) {
    if ( window.hasFocus() ) {
      
      sf::Event event;
      while (window.pollEvent(event)) {
	
	if (event.type == sf::Event::Closed) {
	  window.close();
	}
	else if (event.type == sf::Event::KeyPressed) {
	  // std::cout << "Key pressed!" << std::endl; 
	}
      }

      game.update(window);
  
      window.clear();
      game.render(window);
      window.display();
    }
  }

  return 0;
}
