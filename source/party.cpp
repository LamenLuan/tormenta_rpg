#include "../headers/party.hpp"

Party::Party()
:
    m_inventory(), m_heroes{}
{
}

Party::~Party() = default;

void Party::set_coins(unsigned int t_coins)
{
    if(t_coins != static_cast<int>(m_coins) && t_coins >= 0)
    {
        // Subtracting the weight of the actual quantity.
        m_inventory.set_currentWeight
            (m_inventory.get_currentWeight() - (m_coins * 0.01f));
        m_coins = t_coins;
        // Adding the weight of the new quantity.
        m_inventory.set_currentWeight
            (m_inventory.get_currentWeight() + (m_coins * 0.01f));
    }
}

unsigned int Party::get_coins()
{
    return m_coins;
}

Inventory& Party::get_inventory()
{
    return m_inventory;
}

std::array<std::unique_ptr<Hero>, 4>& Party::get_heroes()
{
    return m_heroes;
}