#include "../headers/rollSet.hpp"

DiceRoll RollSet::m_random;

RollSet::RollSet()
{
}

RollSet::RollSet(uint8_t t_quantity, Dice t_dice)
    :
    m_quantity(t_quantity), m_dice(t_dice)
{
}

RollSet::~RollSet()
{
}

short RollSet::get_quantity() const { return m_quantity; }

Dice RollSet::get_dice() const { return m_dice; }

void RollSet::set_quantity(const uint8_t t_quantity) { m_quantity = t_quantity; }

void RollSet::set_dice(const Dice t_dice) { m_dice = t_dice; }

std::vector<unsigned short> RollSet::roll()
{
    std::vector<unsigned short> rollSet;

    for (size_t i = 0; i < m_quantity; i++)
        rollSet.push_back(m_random(m_dice) );

    return rollSet;
}

const std::string RollSet::show() const
{
    return std::to_string(m_quantity) + "d" +
           std::to_string(static_cast<int>(m_dice));
}