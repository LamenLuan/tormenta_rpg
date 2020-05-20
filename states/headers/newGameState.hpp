#include "characterCreationState.hpp"
#include "gameState.hpp"

#ifndef TORMENTA_NEW_GAME_STATE_HPP
#define TORMENTA_NEW_GAME_STATE_HPP

class NewGameState : public PlayableState
{
private:
    
public:
    NewGameState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    ~NewGameState();

    void update();
};

#endif