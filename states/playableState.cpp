#include "./headers/playableState.hpp"

PlayableState::PlayableState
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::stack< std::unique_ptr<State> >& t_states
)
:
m_heroes(t_heroes), m_states(t_states)
{
}

PlayableState::~PlayableState() = default;

std::array<std::unique_ptr<Hero>, 4>& PlayableState::get_heroes()
{
    return m_heroes;
}

std::stack< std::unique_ptr<State> >& PlayableState::get_states()
{
    return m_states;
}

void PlayableState::printCancelOption()
{
    std::cout << "(0) Cancel" << '\n';
}