/*
  Studio Bakemono, 2018
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <iostream>
#include <string>


#include "State.hpp"
#include "PlayerVsComputerMode.hpp"


const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const uint16_t FRAME_RATE = 60;
const float MAX_VELOCITY = 5.0;


int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!",
			  // No resize button on our window
			  sf::Style::Close,
			  // (feature we're not using, feature we're not using, AntiAliasing level 8, more optional args are unset..)
			  sf::ContextSettings(0, 0, 8)
			  );
  
  window.setFramerateLimit(FRAME_RATE);

  // Load the font used in the game
  sf::Font font;
  if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    std::cout << "Error loading font\n";
    return -1;
  }


  State* currentState = nullptr;

  currentState = new PlayerVsCompState(font);
  currentState->onEnter(window);


  
  while ( window.isOpen() ) {
    if ( window.hasFocus() ) {
      
      sf::Event event;
      while (window.pollEvent(event)) {
	if (event.type == sf::Event::Closed) {

	  // if the window gets closed
	  delete currentState;
	  window.close();

	  
	}
	else if (event.type == sf::Event::KeyPressed) {
	  // std::cout << "Key pressed!" << std::endl; 
	}
      }
  
      // Update 

      currentState->update(window);

      
      // Render
      window.clear();

      currentState->render(window);
          
      window.display();
    }
  }

  
  return 0;
}
