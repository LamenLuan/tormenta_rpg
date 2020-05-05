#include "./fileLoader.hpp"

#include <fstream>

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:

    bool m_gameStarted;
    std::array<Hero*, 4> m_heroes;
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