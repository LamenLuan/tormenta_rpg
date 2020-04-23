#include "../headers/hero.hpp"

// Used by constructors.
void Hero::manageExp(uint8_t t_level)
{
    short i;

    if(t_level > 1u)
    {  
        for (i = 1; i < t_level - 1; i++)
            m_currentExp += i * 1000u;

        addExp(i * 1000u);
    }
}

Hero::Hero(uint8_t t_level) : Character()
{
    manageExp(t_level);
}

Hero::Hero(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, uint8_t t_lifePerLevel,
        Race t_race, int t_coins, unsigned int t_currentExp)
    :
    Character(t_name, t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, 1,
        (4 * t_lifePerLevel) + modifier(t_constitution),
        t_race, t_coins),
    m_lifePerLevel(t_lifePerLevel)
{
    manageExp(t_level);
    m_currentLife = m_maxLife;

    if(t_currentExp) m_currentExp = t_currentExp;
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
            m_maxLife += m_lifePerLevel + modifier(m_constitution);
            m_nextLevelExp += m_level * 1000u;
        }
    }
}

std::string Hero::getIdAsString() const
{
    std::stringstream stream;

    stream << Character::getIdAsString() << " " << m_currentExp;

    return stream.str();
}