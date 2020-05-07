#include "../headers/game.hpp"

Game::Game()
    :
    m_gameStarted(false), m_heroes{}
{
    m_states.push( std::make_unique<GameState>( GameState(m_heroes) ) );
}

Game::~Game() = default;

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

void Game::loadEquippedItems(std::istringstream& input, uint8_t index)
{
    char itemClass = '0';

    // Loading the equipped items saved with the hero.
    while(input >> itemClass)
    {
        switch (itemClass)
        {
            case 'W': m_heroes[index]->set_equippedWeapon
            (
                FileLoader::loadWeapon(input)
            );
            break;
            case 'S': m_heroes[index]->set_equippedShield
            (
                FileLoader::loadShield(input)
            );
            break;
            case 'A': m_heroes[index]->set_equippedArmor
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
    
    // Loading the inventory items line by line.
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
                case 'G': m_heroes[i].reset
                (
                    FileLoader::loadHero<Warrior>(input)
                );
                break;
            } // switch

            loadEquippedItems(input, i);

            loadInventory(i);

        } // if
        else if (anyHero) break;
        else return false;
    }

    heroFile.close();
    return true;
}

void Game::start()
{
    loadHeroes();

    m_states.top()->update();
}