#include "../headers/game.hpp"

Game::Game()
    :
    m_quit(false), m_heroes{}
{
    m_states.push
    (
        std::make_unique<MainMenuState>( MainMenuState(m_heroes, m_states) )
    );
    loadHeroes();
}

Game::~Game() = default;

bool Game::get_quit() const { return m_quit; }

void Game::set_quit(bool t_quit)
{
    m_quit = t_quit;
}

void Game::update()
{
    if( m_states.top()->get_quit() )
    {
        m_states.pop();

        if( m_states.empty() ) m_quit = true;
    }
    else
    {
        m_states.top()->update();
    }
}