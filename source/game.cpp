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
    std::ofstream file;
    file.open("./data/heroes.dat", std::ios::out);

    for(size_t i = 0; i < 4; i++)
    {
        if(m_heroes[i]) 
        {
            file << m_heroes[i]->getIdAsString() << '\n';
        }
        else break;
    }

    file.close();
}

void Game::loadHeroes()
{
    char item = '0', heroClass;
    std::string hero;
    std::ifstream file;

    file.open("./data/heroes.dat", std::ios::in);

    for(size_t i = 0; i < 4; i++)
    {
        if( std::getline(file, hero) )
        {
            if( hero.empty() ) continue;
            std::istringstream input(hero);

            input >> heroClass;

            switch (heroClass)
            {
            case 'G': m_heroes[i] = fileLoader.loadHero<Warrior>(input); break;
            }

            while(input >> item)
            {
                switch (item)
                {
                    case 'W': m_heroes[i]->set_equipedWeapon
                    (
                        fileLoader.loadWeapon(input)
                    );
                    break;
                    //case 'S': m_heroes[i]->set_equipedShield( loadShield(input) );
                        break;
                    //case 'A': m_heroes[i]->set_equipedArmor( loadArmor(input) );
                break;  
                }
            }
        }
        else break;
    }

    file.close();
}