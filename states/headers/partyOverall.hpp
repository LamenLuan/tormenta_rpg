#include "playableState.hpp"

#ifndef TORMENTA_PARTYOVERALL_HPP
#define TORMENTA_PARTYOVERALL_HPP

class PartyOverall : public PlayableState
{
private:
    
public:
    PartyOverall
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~PartyOverall();

    void update();
};

#endif