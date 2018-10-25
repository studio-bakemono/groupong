/*
  Studio Bakemono, 2018
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <thread>
#include <iostream>
#include <string>


#include "Util.hpp"
#include "config.hpp"
#include "Game.hpp"

void fixed_main(volatile bool *running, World **render_world, std::mutex *render_world_mutex){
  World fixed_game = **render_world;
  sf::Clock clock;
  while(*running){
    fixed_game.update();
    {
      World *fresh_world = new World();
      *fresh_world=fixed_game;
      render_world_mutex->lock();
      World *stale_game = *render_world;
      *render_world = fresh_world;
      render_world_mutex->unlock();
      delete stale_game;
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/UPDATE_RATE - clock.restart().asMilliseconds()));
  }
}

int main()
{

  sf::RenderWindow window(
    sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    "pong!",
    // No resize button on our window
    sf::Style::Close,
    // (feature we're not using, feature we're not using, AntiAliasing level 8, more optional args are unset..)
    sf::ContextSettings(0, 0, 8)
  );

  // Load the font used in the game
  sf::Font font;
  if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    std::cout << "Error loading font\n";
    return -1;
  }
  
  Game game(window, font);
  
  volatile bool fixed_thread_running = true;
  std::thread fixed_thread(fixed_main, &fixed_thread_running, &game.world, &game.world_mutex);

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
      window.clear();
      game.render(window);
      window.display();
    }
  }
  fixed_thread_running=false;
  fixed_thread.join();
}
