#include "playableState.hpp"

#ifndef TORMENTA_GAMESTATE_HPP
#define TORMENTA_GAMESTATE_HPP

class GameState : public PlayableState
{
private:
    
public:
    GameState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    ~GameState();

    void update();
};

#endif