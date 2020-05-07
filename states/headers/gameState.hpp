#include "state.hpp"
#include "../../headers/hero.hpp"

#ifndef TORMENTA_GAMESTATE_HPP
#define TORMENTA_GAMESTATE_HPP

class GameState : public State
{
private:
    std::array<Hero*, 4>& m_heroes;
public:
    GameState(std::array<Hero*, 4>& t_heroes);
    virtual ~GameState();

    void update();
};

#endif