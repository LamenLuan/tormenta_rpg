#include "playableState.hpp"
#include "partyOverallState.hpp"
#include "inventoryState.hpp"

#ifndef TORMENTA_GAME_STATE_HPP
#define TORMENTA_GAME_STATE_HPP

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