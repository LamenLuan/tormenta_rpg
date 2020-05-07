#include "./headers/gameState.hpp"

GameState::GameState(std::array<std::unique_ptr<Hero>, 4>& t_heroes)
:
State(),
m_heroes(t_heroes)
{
}

GameState::~GameState()
{
}

void GameState::update()
{
    std::vector<std::string> options =
        {"New game", "Load game", "About"};
    int choice = -1;

    // Load option removed if there's no data saved in files.
    if( !m_heroes[0] ) options.erase(options.begin() + 1);

    while ( !get_quit() )
    {
        system("CLS");

        std::cout << "TORMENTA RPG" << "\n\n";

        for (size_t i = 0; i < options.size(); ++i)
        {
            std::cout << '(' << i + 1 << ") " << options[i] << '\n';
        }

        std::cout << "(0) Quit" << '\n';

        choice = getIntChoice();

        if(choice < 0) continue;
        if(choice == 0)
        {
            set_quit(true);
            continue;
        }
    }

    system("CLS");
}