/*
  Studio Bakemono, 2018
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <mutex>
#include <iostream>
#include <string>

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include "AIPaddle.hpp"

#include "Paddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include "AIPaddle.hpp"
#include "Util.hpp"
#include "MiddleLine.hpp"

struct World{
    World();
    World(sf::Font &);
    void update();

    Scoreboard scoreboard;
    Paddle playerPaddle;
    AIPaddle aiPaddle;
    Ball ball;
    int consecutiveCollisions;
};

class Game{
public:
    explicit Game(sf::RenderWindow &, sf::Font &);
    Game();
    ~Game();

    void update();
    void render(sf::RenderWindow &);

    World *world;
    std::mutex world_mutex;

private:
    MiddleLine middle_line;

    sf::SoundBuffer buffer_hit_paddle;
    sf::SoundBuffer buffer_miss_ball;
    sf::SoundBuffer buffer_hit_wall;
    
    sf::Sound sound_hit_paddle;
    sf::Sound sound_miss_ball;
    sf::Sound sound_hit_wall;
};