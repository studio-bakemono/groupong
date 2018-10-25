/*
  Studio Bakemono, 2018
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <iostream>
#include <string>


#include "Paddle.hpp"
#include "PlayerPaddle.hpp"
#include "Ball.hpp"
#include "Scoreboard.hpp"
#include "AIPaddle.hpp"
#include "Util.hpp"
#include "MiddleLine.hpp"

class World{
public:
    explicit World(sf::Font &);

};

class Game{
public:
    explicit Game(sf::RenderWindow &, sf::Font &);

    void update(sf::RenderWindow &);
    void render(sf::RenderWindow &);

private:
    MiddleLine middle_line;

    sf::SoundBuffer buffer_hit_paddle;
    sf::SoundBuffer buffer_miss_ball;
    sf::SoundBuffer buffer_hit_wall;
    
    sf::Sound sound_hit_paddle;
    sf::Sound sound_miss_ball;
    sf::Sound sound_hit_wall;

    Scoreboard scoreboard;
    PlayerPaddle playerPaddle;
    AIPaddle aiPaddle;
    Ball ball;
};