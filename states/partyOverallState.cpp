#include "./headers/partyOverallState.hpp"

PartyOverallState::PartyOverallState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
    PlayableState(t_party, t_states)
{
}

PartyOverallState::~PartyOverallState() = default;

void PartyOverallState::update()
{
    bool previous = false, next = false;
    int choice = -1;
    std::array<std::unique_ptr<Hero>, 4>& heroes = get_party().get_heroes();

    for (size_t i = 0; !get_quit();)
    {
        system("CLS");

        std::cout << "HEROES SHEET" << "\n\n";

        std::cout << "Hero " << i + 1 << '\n';

        std::cout << *heroes[i] << "\n\n";

        if(i > 0)
        {
            previous = true;
            std::cout << "(1) Previous" << '\n';
        }

        if(i < 4)
        {
            if(heroes[i + 1])
            {
                next = true;
                std::cout << "(2) Next" << '\n';
            }
        }

        std::cout << "(0) Quit" << '\n';

        choice = getIntChoice();

        if(choice < 0) continue;
        switch (choice)
        {
            case 0: set_quit(true); break;
            
            case 1:
            {
                if(previous)
                {
                    --i;
                    previous = false;
                }
            } break;

            case 2:
            {
                if(next)
                {
                    ++i;
                    next = false;
                }
            } break;

            default: break;
        }
    }
}