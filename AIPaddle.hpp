#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class AIPaddle : public Paddle {
public:
  // Inheret Paddle's constructor
  using Paddle::Paddle;
  
  // void update(sf::RenderWindow& window) override {
  //   if(AIWantsToMoveUp()) {
  //    moveUp()
  //   }
  //   if(AIWantsToMoveDown()) {
  //    moveDown()
  //   }
  // }

   
}; 
