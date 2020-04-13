#include "../headers/hero.hpp"

// Used by constructors.
void Hero::util_manageExp(uint8_t t_level)
{
    short i;

    for (i = 1; i < t_level - 1; i++)
        m_currentExp += i * 1000u;
    addExp((i - 1) * 1000u);
}

Hero::Hero(uint8_t t_level) : Character()
{
    util_manageExp(t_level);
}

Hero::Hero(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    Race t_race, int t_coins)
    :
    Character(t_name, t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, 1, t_maxLife, t_race, t_coins)
{
    util_manageExp(t_level);
}

Hero::~Hero()
{
}

unsigned int Hero::get_currentExp() const { return m_currentExp; }

void Hero::addExp(int t_exp)
{
    if(t_exp > 0)
    {
        if(m_currentExp + t_exp > 190000u) m_currentExp = 190000u;
        else m_currentExp += t_exp;

        // Loop allows to up multiple levels in one function call.
        while (m_currentExp >= m_nextLevelExp)
        {
            m_level++;
            m_nextLevelExp += m_level * 1000u;
        }
    }
}