#include "../headers/game.hpp"

int main() {

    Game game;

    while ( !game.get_quit() )
    {
        game.update();
    }
    
    return 0;
}