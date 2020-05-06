#include "./fileLoader.hpp"

#include <fstream>

#include "utils.hpp"

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:

    bool m_gameStarted{false};
    std::array<Hero*, 4> m_heroes;

public:

    Game();
    ~Game();

    bool get_gameStarted() const;

    void set_gameStarted(bool t_gameStarted);

    void saveHeroes();
    void loadEquipedItens(std::istringstream& input, uint8_t index);
    void loadInventory(uint8_t index);
    bool loadHeroes();

    void init();

    void test();
};
 
#endif