#include "Scoreboard.hpp"

void Scoreboard::render(sf::RenderWindow& window) {
  for (int i = 0; i < PLAYER_COUNT; i++ ) {
    window.draw( playerScore[i] );
  }
}
