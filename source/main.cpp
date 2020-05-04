#include "../headers/game.hpp"

int main() {

    Warrior chara;

    chara.set_name("Char");
    chara.set_inteligence(1);

    std::cout << chara << '\n';

    return 0;
}