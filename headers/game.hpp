#include "./fileLoader.hpp"

#include <fstream>

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:

    bool m_gameStarted;
    Hero* m_heroes[4];
    FileLoader fileLoader;

public:

    Game();
    ~Game();

    void saveHeroes();
    void loadEquipedItens(std::istringstream& input, uint8_t index);
    void loadInventory(uint8_t index);
    void loadHeroes();

    void test();
};
 
#endif