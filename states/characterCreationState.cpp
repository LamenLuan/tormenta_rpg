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

void CharacterCreationState::characterCreationLogo()
{
    system("CLS");

    std::cout << "CHARACTER CREATION" << "\n\n";
}

void CharacterCreationState::classSelection(std::unique_ptr<Hero>& hero)
{
    int choice = -1;

    ++m_phaseCount;

    std::cout << "Define your hero's class:" << '\n'
        << "(1) Warrior" << '\n';
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();
    if(choice > 0)
    {
        switch (choice)
        {
            case 1: hero = std::make_unique<Warrior>(); break;
            default: break;
        }
    }
}

void CharacterCreationState::raceSelection(std::unique_ptr<Hero>& hero)
{
    int choice = -1;
    std::vector<std::string> races =
        {
            "Dwarf", "Elf", "Gnoll", "Goblin", "Human"
        };

    ++m_phaseCount;

    std::cout << "Now, choose the hero's race:" << '\n';
    for (size_t i = 0, j = races.size(); i < j; i++)
    {
        std::cout << '(' << i + 1 << ") " << races[i] << '\n';
    }
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();

    if( choice > 0 && choice <= races.size() )
        hero->set_race( static_cast<Race>(choice - 1) );
}

void CharacterCreationState::update()
{
    std::unique_ptr<Hero> hero(nullptr);

    while ( m_phaseCount >= 0 )
    {
        characterCreationLogo();

        try
        {
            switch (m_phaseCount)
            {
                case 0: classSelection(hero); break;
                case 1: raceSelection(hero); break;
                
                default: break;
            }
        }
        catch(const CancelException& e)
        {
            m_phaseCount -= 2;
            if(m_phaseCount == -1)
            {
                set_quit(true);
                break;
            }
        }
    }
}