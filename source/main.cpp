#include "../headers/game.hpp"

int main(int, char**) {
    Hero char1("Fernando", 11, 14, 12, 15, 9, 15, 5, 5, Race::HUMAN, 0);

    std::cout << char1.getIdAsString() << '\n';

    return 0;
}