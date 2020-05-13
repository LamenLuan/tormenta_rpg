#include "./headers/gameState.hpp"

GameState::GameState
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_heroes, t_states)
{
}

GameState::~GameState() = default;

void GameState::update()
{
    int choice = -1;

    system("CLS");

    std::cout << "HERO SHEET" << "\n\n";

    std::cout << *get_heroes()[0] << "\n\n";

    std::cout << "Options:" << '\n'
        << "(0) Quit" << '\n'
        << "(1) Save game" << '\n';

    choice = getIntChoice();

    switch (choice)
    {
        case 0: set_quit(true); break;
        case 1: FileDealer::saveHeroes( get_heroes() ); break;
        default: break;
    }
}