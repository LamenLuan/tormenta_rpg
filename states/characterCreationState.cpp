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
        << "Stats Order: (STR, DEX, CON, INT, WIS, CHA)" << '\n'
        << "(1) Warrior (17, 13, 15, 8, 12, 10)" << '\n';
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();
    switch (choice)
    {
        case 1: hero = std::make_unique<Warrior>(); break;
        default: --m_phaseCount; break;
    }
}

void CharacterCreationState::humanBonusSelection(std::unique_ptr<Hero>& hero)
{
    bool confirmed = false;
    int selected[2], choice;
    std::vector<std::string> habilities =
    {
        "Strength", "Dexterity", "Constitution", "Inteligence",
        "Wisdom", "Charisma"
    };

    while(!confirmed)
    {
        for (size_t i = 0; i < 2; i++)
            selected[i] = -1;

        for (size_t i = 0; i < 2;)
        {
            characterCreationLogo();

            std::cout << "Choose 2 habilities to gain a +2 bonus:" << '\n';

            if(selected[0] > -1)
                std::cout << habilities[ selected[0] ] << " chosen." << '\n';

            for (size_t j = 0; j < habilities.size(); ++j)
            {
                if(j != selected[0] && j != selected[1])
                    std::cout << '(' << j + 1 << ") " << habilities[j] << '\n';
            }
            printCancelOption();
            
            choice = getIntChoice();
            if(choice == 0) throw CancelException();
            
            --choice;

            if(choice < 0 || choice > 5) continue;
            if(choice == selected[0] || choice == selected[1]) continue;

            selected[i] = choice;

            ++i;
        }

        while (!confirmed)
        {
            characterCreationLogo();

            std::cout << "Accept " << habilities[selected[0]] << " and " 
                << habilities[selected[1]] << " ?" << '\n'
                << "(1) Yes" << '\n'
                << "(0) No" << '\n';

            choice = getIntChoice();

            if(choice == 0) break;
            if(choice == 1) confirmed = true;
        }
    }

    for (size_t i = 0; i < 2; i++)
    {
        switch (selected[i])
        {
            case 0: hero->set_strength(hero->get_strength() + 2); break;
            case 2: hero->set_dexterity(hero->get_dexterity() + 2); break;
            case 1: hero->set_constitution(hero->get_constitution() + 2); break;
            case 3: hero->set_inteligence(hero->get_inteligence() + 2); break;
            case 4: hero->set_wisdom(hero->get_wisdom() + 2); break;
            case 5: hero->set_wisdom(hero->get_wisdom() + 2); break;
        }
    }
}

void CharacterCreationState::raceSelection(std::unique_ptr<Hero>& hero)
{
    int choice = -1;
    std::vector<std::string> races =
        {
            " Dwarf (+4 CON, +2 WIS, -2 DEX)",
            " Elf (+4 DEX, +2 INT, -2 CON)",
            " Gnoll (+4 CON, +2 WIS, -2 INT)",
            " Goblin (+4 DEX, +2 CON, -2 CHA)",
            " Human (+2 ON 2 HABILITIES TO CHOOSE)"
        };

    ++m_phaseCount;

    std::cout << "Now, choose the hero's race:" << '\n';
    for (size_t i = 0, j = races.size(); i < j; i++)
    {
        std::cout << '(' << i + 1 << ')' << races[i] << '\n';
    }
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();

    if( choice > 0 && choice <= races.size() )
    {
        hero->set_race( static_cast<Race>(choice - 1) );

        switch ( hero->get_race() )
        {
            case Race::DWARF :
            {
                hero->set_constitution( hero->get_constitution() + 4 );
                hero->set_wisdom( hero->get_wisdom() + 2 );
                hero->set_dexterity( hero->get_dexterity() - 2 );
            } break;
            case Race::ELF :
            {
                hero->set_dexterity( hero->get_dexterity() + 4 );
                hero->set_inteligence( hero->get_inteligence() + 2 );
                hero->set_constitution( hero->get_constitution() - 2 );
            } break;
            case Race::GNOLL :
            {
                hero->set_constitution( hero->get_constitution() + 4 );
                hero->set_wisdom( hero->get_wisdom() + 2 );
                hero->set_inteligence( hero->get_inteligence() - 2 );
            } break;
            case Race::GOBLIN :
            {
                hero->set_dexterity( hero->get_dexterity() + 4 );
                hero->set_constitution( hero->get_constitution() + 2 );
                hero->set_charisma( hero->get_charisma() - 2 );
            } break;
            case Race::HUMAN :
            {
                try
                {
                    humanBonusSelection(hero);
                }
                catch(const CancelException& e)
                {
                    --m_phaseCount;
                }
            } break;
        default:
            break;
        }
    }
    else --m_phaseCount;
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