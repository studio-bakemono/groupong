#include "PlayerVsComputerMode.hpp"


void PlayerVsCompState::onEnter(sf::RenderWindow& window) {
 

  if (!buffer_hit_paddle.loadFromFile("assets/ping_pong_8bit_beeep.wav")) {
    std::cout << "Error loading sound\n";
  }

  if (!buffer_miss_ball.loadFromFile("assets/ping_pong_8bit_peeeeeep.wav")) {
    std::cout << "Error loading sound\n";
  }

  if (!buffer_hit_wall.loadFromFile("assets/ping_pong_8bit_plop.wav")) {
    std::cout << "Error loading sound\n";
  }


  sound_hit_paddle.setBuffer(buffer_hit_paddle);
  sound_miss_ball.setBuffer(buffer_miss_ball);
  sound_hit_wall.setBuffer(buffer_hit_wall);

  // Pass font along to scoreboard
  scoreboard = Scoreboard(window, font);
  
  middleLine = MiddleLine(window);
  // Set up paddles:
  // Each paddle's position is set seperately from constructor since it's position is
  // dependent on it's own size, which is set in the constructor.

  
  ball = Ball(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
  
  playerPaddle = Paddle( sf::Vector2f(20, 100),
			 sf::Color::Red, sf::Keyboard::W, sf::Keyboard::S
			 );
  playerPaddle.setPosition(sf::Vector2f( 20, (window.getSize().y/2 - (playerPaddle.getSize().y/2)) ));
  

  AIpaddle = Paddle( sf::Vector2f(20, 100),
		     sf::Color::Blue,sf::Keyboard::Up, sf::Keyboard::Down
		     );
  AIpaddle.setPosition( sf::Vector2f(window.getSize().x - (20+AIpaddle.getSize().x),
				     window.getSize().y/2 - (AIpaddle.getSize().y/2) ));
  

}

void PlayerVsCompState::onEvent() {

}

void PlayerVsCompState::update(sf::RenderWindow& window) {
  playerPaddle.update(window);
  AIpaddle.update(window);
    
  // Colision detection
  if ( ball.velocity.x < 0.0f && playerPaddle.rect.getGlobalBounds().intersects(ball.collider) ||
       ball.velocity.x > 0.0f && AIpaddle.rect.getGlobalBounds().intersects(ball.collider)) {
      
    //unsure exactly how velocity will change, fix this later
    if(ball.velocity.x < MAX_VELOCITY && ball.velocity.y < MAX_VELOCITY &&
       ball.velocity.x > -MAX_VELOCITY && ball.velocity.y > -MAX_VELOCITY){
      ball.velocity.x *= -1.5f;
      ball.velocity.y *= 1.5f;
      sound_hit_paddle.play();
    }
    else {
      ball.velocity.x *= -1.f;
      ball.velocity.y *= 1.f;
      sound_hit_paddle.play();
    }
    //ball.velocity.y *= 1;
  }

  if (ball.collider.top < 0 || ball.collider.top + ball.collider.height > window.getSize().y) {
    ball.velocity.y *= -1;
    sound_hit_wall.play();
  }
    
  ball.update(window);
      
  
  //Score update
  if(ball.collider.left + ball.collider.width*2/3 > window.getSize().x  ) {
    scoreboard.updateScore(0);
    ball.reset(window);
    sound_miss_ball.play();
  }
  if(ball.collider.left + (ball.collider.width/3) < 0) {
    scoreboard.updateScore(1);
    ball.reset(window);
    sound_miss_ball.play();
  }

}


void PlayerVsCompState::render(sf::RenderWindow& window) {

  playerPaddle.render(window);
  AIpaddle.render(window);
    
  ball.render(window);
  scoreboard.render(window);
  middleLine.render(window);
  
}
