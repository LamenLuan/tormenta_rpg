#include "./headers/playableState.hpp"

PlayableState::PlayableState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
m_party(t_party), m_states(t_states)
{
}

PlayableState::~PlayableState() = default;

Party& PlayableState::get_party()
{
    return m_party;
}

std::stack< std::unique_ptr<State> >& PlayableState::get_states()
{
    return m_states;
}