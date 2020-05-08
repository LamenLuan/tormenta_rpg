#include "./headers/characterCreationState.hpp"

CharacterCreationState::CharacterCreationState
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_heroes, t_states)
{
}

CharacterCreationState::~CharacterCreationState() = default;

void CharacterCreationState::update()
{
    int choice = -1;

    system("CLS");

    std::cout << "CHARACTER CREATION" << "\n\n";
    
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) set_quit(true);
}