/*
  Studio Bakemono, 2018
*/
#include "Game.hpp"
#include "config.hpp"

Game::Game(sf::RenderWindow &window, sf::Font &font) :
        middle_line(),
        scoreboard(font),
        playerPaddle(sf::Vector2f(20, 100), sf::Color::Red),
        aiPaddle(sf::Vector2f(20, 100), sf::Color::Blue),
        ball(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2))
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


    // Set up paddles:
    // Each paddle's position is set seperately from constructor since it's position is
    // dependent on it's own size, which is set in the constructor.

    playerPaddle.setPosition(sf::Vector2f( 20, (WINDOW_HEIGHT/2 - (playerPaddle.getSize().y/2)) ));

    aiPaddle.setPosition( sf::Vector2f(WINDOW_WIDTH - (20+aiPaddle.getSize().x),
    WINDOW_HEIGHT/2 - (aiPaddle.getSize().y/2) ));
}

void Game::update(sf::RenderWindow &window){
    playerPaddle.update(window);
    aiPaddle.update(window);

    // Colision detection
    if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider) ||
        aiPaddle.rect.getGlobalBounds().intersects(ball.collider)) {


        sf::FloatRect collision;

        if (playerPaddle.rect.getGlobalBounds().intersects(ball.collider, collision)) {
            // Debug printing
            std::cout << "PlayerPaddle Collision: [ x: "<< collision.left << " y: " << collision.top << " "
                << " w :" << collision.width << " h: " << collision.height << "]" << std::endl;
        }

        if (aiPaddle.rect.getGlobalBounds().intersects(ball.collider, collision)) {
            // Debug printing
            std::cout << "AIPaddle Collision: [ x: "<< collision.left << " y: " << collision.top << " "
                << " w :" << collision.width << " h: " << collision.height << "]" << std::endl;
        }

        //unsure exactly how velocity will change, fix this later
        if(ball.velocity.x < MAX_VELOCITY && ball.velocity.y < MAX_VELOCITY){
            ball.velocity.x *= -1.5f;
            ball.velocity.y *= 1.5f;
            sound_hit_paddle.play();
        } else {
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

    ball.update(window);


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
}

void Game::render(sf::RenderWindow &window){
    playerPaddle.render(window);
    aiPaddle.render(window);

    ball.render(window);
    scoreboard.render(window);
    middle_line.render(window);
}