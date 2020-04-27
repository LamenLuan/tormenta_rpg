#include "../headers/game.hpp"

int main(int, char**) {

    Game game;

    game.loadHeroes();

    game.saveHeroes();

    return 0;
}