#include "../headers/game.hpp"

Game::Game()
    :
    m_gameStarted(false), m_heroes{}
{
}

Game::~Game()
{
}

bool Game::get_gameStarted() const { return m_gameStarted; }

void Game::set_gameStarted(bool t_gameStarted)
{
    m_gameStarted = t_gameStarted;
}

void Game::saveHeroes()
{
    std::ofstream heroesFile, inventoryFile;
    heroesFile.open("./data/heroes.dat", std::ios::out);

    for(size_t i = 0; i < 4; i++)
    {
        if(m_heroes[i]) 
        {
            heroesFile << m_heroes[i]->getIdAsString() << '\n';
            inventoryFile.open
            (
                "./data/inventory" + std::to_string(i) + ".dat", std::ios::out
            );
            
            for (auto &i : m_heroes[i]->get_backpack().get_items() )
            {
                inventoryFile << i->getIdAsString() << '\n';
            }

            inventoryFile.close();
        } // if
        else break;
    }

    heroesFile.close();
}

void Game::loadEquipedItens(std::istringstream& input, uint8_t index)
{
    char itemClass = '0';

    // Loading the equiped items saved with the hero.
    while(input >> itemClass)
    {
        switch (itemClass)
        {
            case 'W': m_heroes[index]->set_equipedWeapon
            (
                FileLoader::loadWeapon(input)
            );
            break;
            case 'S': m_heroes[index]->set_equipedShield
            (
                FileLoader::loadShield(input)
            );
            break;
            case 'A': m_heroes[index]->set_equipedArmor
            (
                FileLoader::loadArmor(input)
            );
            break;  
        } // switch
    }
}

void Game::loadInventory(uint8_t index)
{
    char itemClass;
    std::string itemString;
    std::ifstream inventoryFile;

    inventoryFile.open
    (
        "./data/inventory" + std::to_string(index) + ".dat", std::ios::in
    );
    
    // Loading the inventory itens line by line.
    while( std::getline(inventoryFile, itemString) )
    {
        std::istringstream input(itemString);

        input >> itemClass;

        FileLoader::loadItem
        (
            m_heroes[index]->get_backpack(), input, itemClass
        );
    }

    inventoryFile.close();
}

bool Game::loadHeroes()
{
    bool anyHero = false;
    char heroClass;
    std::string hero;
    std::ifstream heroFile;

    heroFile.open("./data/heroes.dat", std::ios::in);

    for(size_t i = 0; i < 4; i++)
    {
        if( std::getline(heroFile, hero) )
        {
            if( hero.empty() ) continue;
            anyHero = true;

            std::istringstream input(hero);

            input >> heroClass;

            switch (heroClass)
            {
                case 'G': m_heroes[i] = FileLoader::loadHero<Warrior>(input);
                break;
            } // switch

            loadEquipedItens(input, i);

            loadInventory(i);

        } // if
        else if (anyHero) break;
        else return false;
    }

    heroFile.close();
    return true;
}

void Game::init()
{
    std::vector<std::string> options =
        {"New game", "Load game", "About"};
    int choice = -1;

    m_gameStarted = true;

    // Load option removed if theres no data saved in files.
    if( !loadHeroes() ) options.erase(options.begin() + 1);

    while (m_gameStarted)
    {
        system("CLS");

        std::cout << "TORMENTA RPG" << "\n\n";

        for (size_t i = 0; i < options.size(); ++i)
        {
            std::cout << '(' << i + 1 << ") " << options[i] << '\n';
        }

        std::cout << "(0) Quit" << '\n';

        choice = Utils::getIntChoice();

        if(choice < 0) continue;
        if(choice == 0)
        {
            m_gameStarted = false;
            continue;
        }
    }
}

void Game::test()
{
    m_heroes[0]->set_equipedShield
    (
        *dynamic_cast<Shield*>
        (
            m_heroes[0]->get_backpack().get_items().at(2)
        )
    );

    m_heroes[0]->get_backpack().removeItem(2);

    std::cout << *m_heroes[0];
}