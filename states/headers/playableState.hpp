#include <stack>

#include "state.hpp"
#include "../../headers/exception-types/cancelException.hpp"
#include "../../headers/fileDealer.hpp"

#ifndef TORMENTA_PLAYABLESTATE_HPP
#define TORMENTA_PLAYABLESTATE_HPP

class PlayableState : public State
{
private:
    std::array<std::unique_ptr<Hero>, 4>& m_heroes;
    std::stack< std::unique_ptr<State> >& m_states;
public:
    PlayableState
    (
        std::array<std::unique_ptr<Hero>, 4>& t_heroes,
        std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~PlayableState();

    std::array<std::unique_ptr<Hero>, 4>& get_heroes();
    std::stack< std::unique_ptr<State> >& get_states();

    void printCancelOption();

    virtual void update() = 0;
};

#endif