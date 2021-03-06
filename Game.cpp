/*
  Studio Bakemono, 2018
*/

#include "Game.hpp"

#include "PlayerVsComputerMode.hpp"

#include <cassert>
#include <iostream>

const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;
const uint16_t FRAME_RATE = 60;

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!",
    // No resize button on our window
    sf::Style::Close,
    // (feature we're not using, feature we're not using, AntiAliasing level 8, more optional args are unset..)
    sf::ContextSettings(0, 0, 8)
){
    window.setFramerateLimit(FRAME_RATE);
    if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    state = new PlayerVsCompState(font);
    state->onEnter(this);
}

void Game::to_state(State *newstate){
    //state->onLeave(window);
    //newstate being state would cause use-after-free
    assert(state!=newstate);
    delete state;
    state = newstate;
    state->onEnter(this);
}

void Game::run_to_completion(){
    while ( window.isOpen() ) {
        if ( window.hasFocus() ) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {

                    // if the window gets closed
                    delete state;
                    window.close();
                    return;

                } else if (event.type == sf::Event::KeyPressed) {
                    // std::cout << "Key pressed!" << std::endl; 
                }
            }

            // Update 
            State *next = state->update(window);
            if(next){
                to_state(next);
            }

            // Render
            window.clear();

            state->render(window);
                
            window.display();
        }
    }
}