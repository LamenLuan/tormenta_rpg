#include "../headers/game.hpp"

Game::Game() 
    :
    m_gameStarted(false), m_heroes{nullptr, nullptr, nullptr, nullptr}
{
} 

Game::~Game()
{
}

void Game:: saveHeroes()
{
    std::ofstream file;

    file.open("../data/heroes.dat", std::ios::out | std::ios::app);

    for (size_t i = 0; i < 4; i++)
    {
        if(m_heroes[i])
        {
            file << m_heroes[i] << '\n';
        }
        else break;
    }

    file.close();
}

void Game::loadHeroes()
{
} 