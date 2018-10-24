#include "MiddleLine.hpp"

void MiddleLine::render(sf::RenderWindow& window) {
    for(auto line: lines) {
        window.draw(line);
    }
}