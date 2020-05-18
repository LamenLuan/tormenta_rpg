#include "./headers/gameState.hpp"

GameState::GameState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_party, t_states)
{
}

GameState::~GameState() = default;

void GameState::update()
{
    int choice = -1;
    std::array<std::unique_ptr<Hero>, 4>& heroes = get_party().get_heroes();

    system("CLS");

    std::cout << "Options:" << '\n'
        << "(0) Quit" << '\n'
        << "(1) Heroes Sheet" << '\n'
        << "(2) Save game" << '\n';

    choice = getIntChoice();

    switch (choice)
    {
        case 0: set_quit(true); break;
        case 1: get_states().push
        (
            std::make_unique<PartyOverall>
            (
                get_party(), get_states()
            )
        );
        case 2: FileDealer::saveHeroes(heroes); break;
        default: break;
    }
}