#pragma once

#include <SFML/Graphics.hpp>


#include "config.hpp"

class MiddleLine {
    public:

        static const int LINE_COUNT = 16;

        sf::RectangleShape lines[LINE_COUNT];

        MiddleLine() {

            for (int i = 0; i < LINE_COUNT; i++ ) { 
                lines[i] = sf::RectangleShape(sf::Vector2f(4, 24));
                lines[i].setFillColor(sf::Color::White);
                lines[i].setPosition(WINDOW_WIDTH / 2, i * 30 + 60);
            }
        }

        void render(sf::RenderWindow& window);
};
