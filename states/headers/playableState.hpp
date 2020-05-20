#include <stack>

#include "state.hpp"
#include "../../headers/exception-types/cancelException.hpp"
#include "../../headers/fileDealer.hpp"

#ifndef TORMENTA_PLAYABLE_STATE_HPP
#define TORMENTA_PLAYABLE_STATE_HPP

class PlayableState : public State
{
private:
    Party& m_party;
    std::stack< std::unique_ptr<State> >& m_states;
public:
    PlayableState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~PlayableState();

    Party& get_party();
    std::stack< std::unique_ptr<State> >& get_states();

    virtual void update() = 0;
};

#endif