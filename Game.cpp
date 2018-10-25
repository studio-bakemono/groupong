/*
  Studio Bakemono, 2018
*/
#include "Game.hpp"
#include "config.hpp"
World::World(){}

World::World(sf::Font &font) : scoreboard(font),
    playerPaddle(sf::Vector2f(20, 100), sf::Color::Red),
    aiPaddle(sf::Vector2f(20, 100), sf::Color::Blue),
    ball(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2)){
    // Set up paddles:
    // Each paddle's position is set seperately from constructor since it's position is
    // dependent on it's own size, which is set in the constructor.

    playerPaddle.setPosition(sf::Vector2f( 20, (WINDOW_HEIGHT/2 - (playerPaddle.getSize().y/2)) ));

    aiPaddle.setPosition( sf::Vector2f(WINDOW_WIDTH - (20+aiPaddle.getSize().x),
    WINDOW_HEIGHT/2 - (aiPaddle.getSize().y/2) ));
}

Game::Game(sf::RenderWindow &window, sf::Font &font) :
        middle_line(),
        world(new World(font))
{
    // Draw the line in the middle separating the players
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
}

void World::update(){
    playerPaddle.update();
    aiPaddle.update();

    // Colision detection
    if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider) ||
        aiPaddle.rect.getGlobalBounds().intersects(ball.collider)) {
        consecutiveCollisions += 1;

        //unsure exactly how velocity will change, fix this later
        if(ball.velocity.x < MAX_VELOCITY && ball.velocity.y < MAX_VELOCITY &&
            ball.velocity.x > -MAX_VELOCITY && ball.velocity.y > -MAX_VELOCITY){
            ball.velocity.x *= -1.5f;
            ball.velocity.y *= 1.5f;
            //sound_hit_paddle.play();
        } else {
            ball.velocity.x *= -1.f;
            ball.velocity.y *= 1.f;
            //sound_hit_paddle.play();
        }
        //ball.velocity.y *= 1;
    } else {
        consecutiveCollisions = 0;
    }

    if (ball.collider.top < 0 || ball.collider.top + ball.collider.height > WINDOW_HEIGHT) {
        ball.velocity.y *= -1;
        //sound_hit_wall.play();
    }

    ball.update();


    //Score update
    if(ball.collider.left + ball.collider.width > WINDOW_WIDTH || 
    (consecutiveCollisions > 1 && ball.collider.left > WINDOW_WIDTH / 2)) {
	    consecutiveCollisions = 0;
      scoreboard.updateScore(0);
    	ball.reset();
	    //sound_miss_ball.play();
	    //should resetting it be a function inside ball?
    }
    if(ball.collider.left  < 0 || 
    (consecutiveCollisions > 1 && ball.collider.left < WINDOW_WIDTH / 2)) {
      consecutiveCollisions = 0;
	    scoreboard.updateScore(1);
    	ball.reset();
    	//sound_miss_ball.play();
    }
}

void Game::render(sf::RenderWindow &window){
    world_mutex.lock();
    
    world->playerPaddle.render(window);
    world->aiPaddle.render(window);

    world->ball.render(window);
    world->scoreboard.render(window);
    middle_line.render(window);

    world_mutex.unlock();
}

Game::~Game(){
    delete world;
}