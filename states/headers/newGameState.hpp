#include "characterCreationState.hpp"
#include "gameState.hpp"

#ifndef TORMENTA_NEWGAMESTATE_HPP
#define TORMENTA_NEWGAMESTATE_HPP

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