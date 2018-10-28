#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdint>

class Scoreboard {
public:
  
  static const uint8_t PLAYER_COUNT = 2;
  
  sf::Text playerScore[PLAYER_COUNT];
  uint16_t score[PLAYER_COUNT] = {}; // Empty list inialization sets whole array to zero

public:
  
  Scoreboard(sf::RenderWindow& window, sf::Font& font) {
    for (int i = 0; i < PLAYER_COUNT; i++ ) { 
      playerScore[i].setFont(font);
      playerScore[i].setFillColor(sf::Color::White);
      playerScore[i].setCharacterSize(48); // in pixels, not points!
      playerScore[i].setString(std::to_string( score[i] ));

      // Conditionals to place the scores in the right location based on player number
      if (i == 0)
	playerScore[i].setPosition(window.getSize().x / 4, 10);
      else if (i == 1)
	playerScore[i].setPosition(window.getSize().x - window.getSize().x / 4, 10);
      
    }
  }

  Scoreboard() {}
  ~Scoreboard() {}

  // +1 to the score of player
  inline void updateScore( uint8_t player ) {
    if (player > PLAYER_COUNT) {
      std::cout << "Error! Player no." << player << " Doesn't exist!" << std::endl; 
    }
    else {
      // Update numerical score and sf::Text to render updated score to board
      score[player] += 1;
      playerScore[player].setString(std::to_string( score[player] ));
    }
  }

  void render(sf::RenderWindow& window);
  
};
