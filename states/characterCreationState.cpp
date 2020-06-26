#include "./headers/characterCreationState.hpp"

CharacterCreationState::CharacterCreationState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_party, t_states)
{
}

CharacterCreationState::~CharacterCreationState() = default;

void CharacterCreationState::printCancelOption()
{
    std::cout << "(0) Cancel" << '\n';
}

void CharacterCreationState::characterCreationLogo()
{
    system("CLS");

    std::cout << "CHARACTER CREATION" << "\n\n";
}

void CharacterCreationState::classSelection
(
    uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
    uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma,
    uint8_t& heroClass
)
{
    int choice = -1;
    std::array<uint8_t, 7> habilitesAndClass;

    ++m_phaseCount;

    std::cout << "First of all, what do he/she do for living?" << "\n\n"
        << "Stats Order: (STR, DEX, CON, INT, WIS, CHA)" << '\n'
        << "(1) Warrior (17, 13, 15, 8, 12, 10)" << '\n';
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();
    switch (choice)
    {
        case 1: habilitesAndClass = {17u, 13u, 15u, 8u, 12u, 10u, 0u}; break;
        default: --m_phaseCount; break;
    }

    strength = habilitesAndClass[0];
    dexterity = habilitesAndClass[1];
    constitution = habilitesAndClass[2];
    inteligence = habilitesAndClass[3];
    wisdom = habilitesAndClass[4];
    charisma = habilitesAndClass[5];
    heroClass = habilitesAndClass[6];
}

void CharacterCreationState::humanBonusSelection
(
    uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
    uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma
)
{
    bool confirmed = false;
    int selected[2], choice;

    const std::array<std::string, 6> habilities =
    {
        "Strength", "Dexterity", "Constitution", "Inteligence",
        "Wisdom", "Charisma"
    };

    while(!confirmed)
    {
        for (size_t i = 0; i < 2; ++i)
            selected[i] = -1;

        for (size_t i = 0; i < 2;)
        {
            characterCreationLogo();

            std::cout << "Choose 2 habilities to gain a +2 bonus:" << "\n\n";

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

    for (size_t i = 0; i < 2; ++i)
    {
        switch (selected[i])
        {
            case 0: strength += 2; break;
            case 2: dexterity += 2; break;
            case 1: constitution += 2; break;
            case 3: inteligence += 2; break;
            case 4: wisdom += 2; break;
            case 5: charisma += 2; break;
        }
    }
}

void CharacterCreationState::raceSelection
(
    uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
    uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma, Race& race
)
{
    int choice = -1;
    const std::array<std::string, 5> races =
        {
            " Dwarf (+4 CON, +2 WIS, -2 DEX)",
            " Elf (+4 DEX, +2 INT, -2 CON)",
            " Gnoll (+4 CON, +2 WIS, -2 INT)",
            " Goblin (+4 DEX, +2 CON, -2 CHA)",
            " Human (+2 ON 2 HABILITIES TO CHOOSE)"
        };

    ++m_phaseCount;

    std::cout << "And do he/she looks like?" << "\n\n";
    for (size_t i = 0, j = races.size(); i < j; ++i)
    {
        std::cout << '(' << i + 1 << ')' << races[i] << '\n';
    }
    printCancelOption();

    choice = getIntChoice();

    if(choice == 0) throw CancelException();

    if( choice > 0 && choice <= races.size() )
    {
        race = static_cast<Race>(choice - 1);

        switch (race)
        {
            case Race::DWARF :
            {
                constitution += + 4;
                wisdom += 2;
                dexterity +=  2;
            } break;
            case Race::ELF :
            {
                dexterity += 4;
                inteligence += 2;
                constitution += 2;
            } break;
            case Race::GNOLL :
            {
                constitution += 4;
                wisdom += 2;
                inteligence += 2;
            } break;
            case Race::GOBLIN :
            {
                dexterity += 4;
                constitution += 2;
                charisma += 2;
            } break;
            case Race::HUMAN :
            {
                try
                {
                    humanBonusSelection
                    (
                        strength, dexterity, constitution, inteligence, wisdom,
                        charisma
                    );
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

void CharacterCreationState::nameSelection(std::string& heroName)
{
    bool validName = false;
    int choice = -1;
    std::string name, error;

    ++m_phaseCount;

    while (!validName)
    {
        if( !error.empty() )
        {
            characterCreationLogo();
            std::cout << error << '\n';
        }
        std::cout << "What is his/her name?" << "\n\n" << ": ";

        std::getline(std::cin, name);

        if(name.size() > 30)
        {
            error = "Hero's name cannot exceed 30 characters!";
            continue;
        }

        validName = true;
    }

    heroName = name;
}

void CharacterCreationState::update()
{
    uint8_t strength = 10u, dexterity = 10u, constitution = 10u,
    inteligence = 10u, wisdom = 10u, charisma = 10u, heroClass = 0u;
    std::string name;
    Race race;

    while ( m_phaseCount < 3 )
    {
        characterCreationLogo();
        try
        {
            switch (m_phaseCount)
            {
                case 0: classSelection
                (
                    strength, dexterity, constitution, inteligence, wisdom,
                    charisma, heroClass
                ); break;
                case 1: raceSelection
                (
                    strength, dexterity, constitution, inteligence, wisdom,
                    charisma, race
                ); break;
                case 2: nameSelection(name); break;
                
                default: break;
            }
        }
        catch(const CancelException& e)
        {
            m_phaseCount -= 2;
            if(m_phaseCount == -1)
            {
                set_quit(true);
                return;
            }
        }
    }

    for ( auto &i : get_party().get_heroes() )
    {
        if(!i)
        {
            switch (heroClass)
            {
                case 0: get_party().addHero
                (
                    new Warrior
                    (
                        name, strength, dexterity, constitution, inteligence,
                        wisdom, charisma, race
                    ), i
                ); break;

            default:
                break;
            }

            break;
        }
    }
    set_quit(true);
}