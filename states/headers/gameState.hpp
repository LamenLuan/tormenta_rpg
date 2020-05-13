#include "playableState.hpp"

#ifndef TORMENTA_GAMESTATE_HPP
#define TORMENTA_GAMESTATE_HPP

class GameState : public PlayableState
{
private:
    
public:
    GameState
    (
        std::array<std::unique_ptr<Hero>, 4>& t_heroes,
        std::stack< std::unique_ptr<State> >& t_states
    );
    ~GameState();

    void update();
};

#endif