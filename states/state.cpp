#include "./headers/state.hpp"

State::State() : m_quit(false)
{
}

State::~State() = default;

bool State::get_quit() const { return m_quit; }

void State::set_quit(bool t_quit) { m_quit = t_quit; }

int State::getIntChoice()
{
    int choice = 0;

    std::cout << '\n' << ": ";

    std::cin >> std::setw(1) >> choice;

    if( !std::cin.good() ) choice = -1;

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    return choice;
}