#include "./fileDealer.hpp"
#include "../states/headers/mainMenuState.hpp"

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

    void update();
};
 
#endif