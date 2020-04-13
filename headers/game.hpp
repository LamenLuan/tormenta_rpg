#include "../source/hero-classes/mage.hpp"
#include "../source/hero-classes/ranger.hpp"
#include "../source/hero-classes/warrior.hpp"

#include <fstream>

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:
    bool m_gameStarted;
    Hero* m_heroes[4];

public:
    Game();
    ~Game();

    void saveHeroes();
    void loadHeroes();
};
 
#endif