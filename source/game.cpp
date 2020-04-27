#include "../headers/game.hpp"

Game::Game()
    :
    m_gameStarted(false), m_heroes{nullptr, nullptr, nullptr, nullptr}
{
}

Game::~Game()
{
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
        }
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
                fileLoader.loadWeapon(input)
            );
            break;
            case 'S': m_heroes[index]->set_equipedShield
            (
                fileLoader.loadShield(input)
            );
            break;
            case 'A': m_heroes[index]->set_equipedArmor
            (
                fileLoader.loadArmor(input)
            );
            break;  
        }
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
        std::istringstream inventory(itemString);

        inventory >> itemClass;

        m_heroes[index]->get_backpack().addItem
        (
            fileLoader.loadItem(inventory, itemClass)
        );
    }

    inventoryFile.close();
}

void Game::loadHeroes()
{
    char heroClass;
    std::string hero;
    std::ifstream heroFile;

    heroFile.open("./data/heroes.dat", std::ios::in);

    for(size_t i = 0; i < 4; i++)
    {
        if( std::getline(heroFile, hero) )
        {
            if( hero.empty() ) continue;
            std::istringstream input(hero);

            input >> heroClass;

            switch (heroClass)
            {
            case 'G': m_heroes[i] = fileLoader.loadHero<Warrior>(input); break;
            }

            loadEquipedItens(input, i);

            loadInventory(i);

        }
        else break;
    }

    heroFile.close();
}