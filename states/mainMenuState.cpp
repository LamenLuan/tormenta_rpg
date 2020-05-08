#include "./headers/mainMenuState.hpp"

MainMenuState::MainMenuState
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_heroes, t_states)
{
}

MainMenuState::~MainMenuState() = default;

void MainMenuState::update()
{
    std::vector<std::string> options =
        {"New game", "Load game", "About"};
    int choice = -1;

    // Load option removed if there's no data saved in files.
    if( !get_heroes()[0] ) options.erase(options.begin() + 1);

    system("CLS");

    std::cout << "TORMENTA RPG" << "\n\n";

    for (size_t i = 0; i < options.size(); ++i)
    {
        std::cout << '(' << i + 1 << ") " << options[i] << '\n';
    }

    std::cout << "(0) Quit" << '\n';

    choice = getIntChoice();

    switch (choice)
    {
        case 0: set_quit(true); break;
        case 1: get_states().push
        (
            std::make_unique<CharacterCreationState>
            (
                CharacterCreationState( get_heroes(), get_states() )
            )
        ); break;
        default: break;
    }
}