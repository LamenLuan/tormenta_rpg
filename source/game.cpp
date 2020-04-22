#include "../headers/game.hpp"

Game::Game()
    :
    m_gameStarted(false), m_heroes{nullptr, nullptr, nullptr, nullptr}
{
    m_heroes[0] =
        new Warrior("Fernando", 11, 14, 12, 15, 9, 15, 5, Race::HUMAN, 0);
} 

Game::~Game()
{
}

void Game:: saveHeroes()
{
    std::ofstream file;

    file.open("./data/heroes.dat", std::ios::out);

    for (size_t i = 0; i < 4; i++)
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
} 