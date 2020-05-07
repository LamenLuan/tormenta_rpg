#include <fstream>
#include <stack>

#include "./fileLoader.hpp"
#include "../states/headers/gameState.hpp"

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:

    bool m_gameStarted{false};
    std::array<std::unique_ptr<Hero>, 4> m_heroes;
    std::stack< std::unique_ptr<State> > m_states;

public:

    Game();
    ~Game();

    bool get_gameStarted() const;

    void set_gameStarted(bool t_gameStarted);

    void saveHeroes();
    void loadEquippedItems(std::istringstream& input, uint8_t index);
    void loadInventory(uint8_t index);
    bool loadHeroes();

    void start();
};
 
#endif