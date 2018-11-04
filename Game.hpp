/*
  Studio Bakemono, 2018
*/

#include "State.hpp"
#include <SFML/Graphics.hpp>

class Game{
public:
    sf::RenderWindow window;
    sf::Font font;

    Game();
    void run_to_completion();

private:
    State* state;
    void to_state(State*);

};
