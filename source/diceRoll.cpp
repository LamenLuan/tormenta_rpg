#include "../headers/diceRoll.hpp"

DiceRoll::DiceRoll() : m_gen(std::random_device{}() )
{
}

DiceRoll::~DiceRoll() = default;

unsigned short DiceRoll::operator()(Dice t_max)
{
    std::uniform_int_distribution<size_t> dist(1, static_cast<size_t>(t_max) );
    return dist(m_gen);
}