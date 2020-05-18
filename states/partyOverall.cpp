#include "./headers/partyOverall.hpp"

PartyOverall::PartyOverall
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
    PlayableState(t_party, t_states)
{
}

PartyOverall::~PartyOverall()
{
}

void PartyOverall::update()
{
    int choice = -1;
    std::array<std::unique_ptr<Hero>, 4>& heroes = get_party().get_heroes();

    system("CLS");

    std::cout << "HEROES SHEET" << "\n\n";
    for (size_t i = 0, options = 0; i < 4 && !get_quit(); options = 0)
    {
        std::cout << *heroes[i] << "\n\n";

        if(i > 0)
        {
            ++options;
            std::cout << "(1) Previous" << '\n';
        }

        if(i < 4)
        {
            if(heroes[i + 1])
            {
                ++options;
                std::cout << "(2) Next" << '\n';
            }
        }

        printCancelOption();

        choice = getIntChoice();

        if(choice < 0 || choice > options) continue;
        switch (choice)
        {
            case 0: set_quit(true); break;
            case 1: --i; break;
            case 2: ++i; break;
            default: break;
        }
    }
}