#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "State.hpp"

#include "Paddle.hpp"
#include "Scoreboard.hpp"
#include "Ball.hpp"

#include "MiddleLine.hpp"

class PlayerVsCompState : public State {
public:

  const float MAX_VELOCITY = 5.0;

  sf::Font font;
  
  // Draw the line in the middle separating the players
  MiddleLine middleLine;
  
  sf::SoundBuffer buffer_hit_paddle;
  sf::SoundBuffer buffer_miss_ball;
  sf::SoundBuffer buffer_hit_wall;

  sf::Sound sound_hit_paddle;
  sf::Sound sound_miss_ball;
  sf::Sound sound_hit_wall;
  
  Ball ball;
  Paddle playerPaddle;
  Paddle AIpaddle;
  Scoreboard scoreboard;

  
  
public:

  PlayerVsCompState(sf::Font font): font(font) {}

  ~PlayerVsCompState() {
  }

  void onEnter(Game *game) override;
  void onEvent() override;
  State *update(sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override; 
  
};
