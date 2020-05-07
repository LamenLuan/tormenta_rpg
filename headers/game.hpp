#include <fstream>
#include <stack>

#include "./fileLoader.hpp"
#include "../states/headers/gameState.hpp"

#ifndef TORMENTA_GAME_HPP
#define TORMENTA_GAME_HPP

class Game
{
private:

    bool m_quit{false};
    std::array<std::unique_ptr<Hero>, 4> m_heroes;
    std::stack< std::unique_ptr<State> > m_states;

public:

    Game();
    ~Game();

    bool get_quit() const;

    void set_quit(bool t_quit);

    void saveHeroes();
    void loadEquippedItems(std::istringstream& input, uint8_t index);
    void loadInventory(uint8_t index);
    bool loadHeroes();

    void update();
};
 
#endif