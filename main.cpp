/*
  Studio Bakemono, 2018
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <cmath>
#include <iostream>
#include <string>


#include "Paddle.hpp"
#include "PlayerPaddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include "AIPaddle.hpp"
#include "Util.hpp"
#include "MiddleLine.hpp"

const uint16_t WINDOW_WIDTH = 800;
const uint16_t WINDOW_HEIGHT = 600;

const float MAX_VELOCITY = 5.0;


int main()
{

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pong!", sf::Style::Default, sf::ContextSettings(0, 0, 8));

  // Load the font used in the game
  sf::Font font;
  if(!font.loadFromFile("assets/AtariClassic-Regular.ttf")) {
    std::cout << "Error loading font\n";
    return -1;
  }

  // Draw the line in the middle separating the players
  MiddleLine middle_line(window);
  sf::SoundBuffer buffer_hit_paddle;
  sf::SoundBuffer buffer_miss_ball;
  sf::SoundBuffer buffer_hit_wall;

  if (!buffer_hit_paddle.loadFromFile("assets/ping_pong_8bit_beeep.wav")) {
    std::cout << "Error loading sound\n";
    return -1;
  }

  if (!buffer_miss_ball.loadFromFile("assets/ping_pong_8bit_peeeeeep.wav")) {
    std::cout << "Error loading sound\n";
    return -1;
  }

  if (!buffer_hit_wall.loadFromFile("assets/ping_pong_8bit_plop.wav")) {
    std::cout << "Error loading sound\n";
    return -1;
  }

  sf::Sound sound_hit_paddle;
  sound_hit_paddle.setBuffer(buffer_hit_paddle);
  sf::Sound sound_miss_ball;
  sound_miss_ball.setBuffer(buffer_miss_ball);
  sf::Sound sound_hit_wall;
  sound_hit_wall.setBuffer(buffer_hit_wall);

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

  sf::Clock clock;
  
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
  

      // Update 
      float frametime = float(clock.restart().asMicroseconds())/1000000.0f;
    
      playerPaddle.update(window, frametime);
      AIpaddle.update(window, frametime);

      // Colision detection
      if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider) ||
	  AIpaddle.rect.getGlobalBounds().intersects(ball.collider)) {


	sf::FloatRect collision;

	if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider, collision)) {
	  // Debug printing
	  std::cout << "PlayerPaddle Collision: [ x: "<< collision.left << " y: " << collision.top << " "
		    << " w :" << collision.width << " h: " << collision.height << "]" << std::endl;
	}

	if (AIpaddle.rect.getGlobalBounds().intersects(ball.collider, collision)) {
	  // Debug printing
	  std::cout << "AIPaddle Collision: [ x: "<< collision.left << " y: " << collision.top << " "
		    << " w :" << collision.width << " h: " << collision.height << "]" << std::endl;
	}
	
	//unsure exactly how velocity will change, fix this later
	if(ball.velocity.x < MAX_VELOCITY && ball.velocity.y < MAX_VELOCITY){
    float factor = pow(1.5f, frametime);
	  ball.velocity.x *= -factor;
	  ball.velocity.y *= factor;
	  sound_hit_paddle.play();
	}
	else {
	  ball.velocity.x *= -1.f;
	  ball.velocity.y *= 1.f;
	  sound_hit_paddle.play();
	}
	//ball.velocity.y *= 1;
      }

      //
      if (ball.collider.top < 0 || ball.collider.top + ball.collider.height > WINDOW_HEIGHT) {
	ball.velocity.y *= -1;
	sound_hit_wall.play();
      }

      ball.update(window, frametime);
      
    
      //Score update
      if(ball.collider.left + ball.collider.width > WINDOW_WIDTH) {
	scoreboard.updateScore(0);
	ball.reset(window);
	sound_miss_ball.play();
	//should resetting it be a function inside ball?
      }
      if(ball.collider.left  < 0) {
	scoreboard.updateScore(1);
	ball.reset(window);
	sound_miss_ball.play();
      }

      // Render
      window.clear();
    
      playerPaddle.render(window);
      AIpaddle.render(window);
    
      ball.render(window);
      scoreboard.render(window);
      middle_line.render(window);

      window.display();
    }
  }

  return 0;
}
