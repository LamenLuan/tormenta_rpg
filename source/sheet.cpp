#include "../headers/sheet.hpp"

Sheet::Sheet
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    unsigned short t_currentLife
)
:
    m_name( std::move(t_name) ), m_strength(t_strength),
    m_dexterity(t_dexterity),  m_constitution(t_constitution),
    m_inteligence(t_inteligence), m_wisdom(t_wisdom), m_charisma(t_charisma),
    m_level(t_level), m_maxLife(t_maxLife)
{
    m_currentLife = m_currentLife ? m_currentLife : t_maxLife;
}

Sheet::~Sheet() = default;

const std::string &Sheet::get_name() const { return m_name; }

unsigned short Sheet::get_level() const { return m_level; }

unsigned short Sheet::get_strength() const { return m_strength; }

unsigned short Sheet::get_dexterity() const { return m_dexterity; }

unsigned short Sheet::get_constitution() const { return m_constitution; }

unsigned short Sheet::get_inteligence() const { return m_inteligence; }

unsigned short Sheet::get_wisdom() const { return m_wisdom; }

unsigned short Sheet::get_charisma() const { return m_charisma; }

unsigned short Sheet::get_maxLife() const { return m_maxLife; }

unsigned short Sheet::get_currentLife() const { return m_currentLife; }

Weapon& Sheet::get_naturalWeapon() const { return *m_naturalWeapon; }

void Sheet::set_name(const std::string& t_name)
{
    if ( !t_name.empty() ) m_name = t_name;
}

void Sheet::set_level(uint8_t t_level)
{
    if(t_level > 0 && t_level <= 20) m_level = t_level;
}

void Sheet::set_strength(uint8_t t_strength)
{
    if(t_strength > 0) m_strength = t_strength;
}

void Sheet::set_dexterity(uint8_t t_dexterity)
{
    if(t_dexterity > 0) m_dexterity = t_dexterity;
}

void Sheet::set_constitution(uint8_t t_constitution)
{
    if(t_constitution > 0) m_constitution = t_constitution;
}

void Sheet::set_inteligence(uint8_t t_inteligence)
{
    if(t_inteligence > 0) m_inteligence = t_inteligence;
}

void Sheet::set_wisdom(uint8_t t_wisdom)
{
    if(t_wisdom > 0) m_wisdom = t_wisdom;
}

void Sheet::set_charisma(uint8_t t_charisma)
{
    if(t_charisma > 0) m_charisma = t_charisma;
}

// Correct possible negative values to accept negative values that could come
// from magic debuffs.
void Sheet::set_maxLife(unsigned short t_maxLife)
{
    if (t_maxLife <= 0) m_maxLife = 1u;
    else m_maxLife = t_maxLife;

    if (m_currentLife > m_maxLife) m_currentLife = m_maxLife;
}

// Correct possible negative values to accept negative values that will come
// from damages.
void Sheet::set_currentLife(unsigned short t_currentLife)
{
    if (t_currentLife < 0) m_currentLife = 0;
    else
    {
        if (m_maxLife < t_currentLife)
            m_currentLife = m_maxLife;
        else
            m_currentLife = t_currentLife;
    }
}

void Sheet::set_naturalWeapon(const Weapon& t_naturalWeapon)
{
    m_naturalWeapon = std::make_unique<Weapon>( t_naturalWeapon );
}

short Sheet::modifier(short t_atribute)
{
    if (t_atribute % 2 != 0) t_atribute -= 1;

    return (t_atribute - 10) / 2;
}

std::ostream &operator<<(std::ostream &t_stream, const Sheet &t_sheet)
{
    t_stream <<t_sheet.show();

    return t_stream;
}