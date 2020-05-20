#include "playableState.hpp"

#ifndef TORMENTA_PARTY_OVERALL_STATE_HPP
#define TORMENTA_PARTY_OVERALL_STATE_HPP

class PartyOverallState : public PlayableState
{
private:
    
public:
    PartyOverallState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~PartyOverallState();

    void update();
};

#endif