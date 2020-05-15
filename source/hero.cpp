#include "../headers/hero.hpp"

Hero::Hero
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_lifePerLevel,
    Race t_race
)
:
    Character
    (
        std::move(t_name), t_strength, t_dexterity, t_constitution,
        t_inteligence, t_wisdom, t_charisma, 1u,
        (4 * t_lifePerLevel) + modifier(t_constitution), t_race, 0u
    ),
    m_lifePerLevel(t_lifePerLevel)
{
}

Hero::Hero
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_lifePerLevel, Race t_race,
    unsigned short t_maxLife, unsigned short t_currentLife,
    unsigned int t_currentExp
)
    :
    Character
    (
        std::move(t_name), t_strength, t_dexterity, t_constitution,
        t_inteligence, t_wisdom, t_charisma, 1u, t_maxLife, t_race,
        t_currentExp
    ),
    m_currentExp(t_currentExp), m_lifePerLevel(t_lifePerLevel)
{
    while (m_currentExp >= m_nextLevelExp)
    {
        m_level++;
        m_nextLevelExp += m_level * 1000u;
    }

    m_currentLife = (t_currentLife ?  t_currentLife : m_maxLife);
}

Hero::~Hero() = default;

unsigned int Hero::get_currentExp() const { return m_currentExp; }

unsigned int Hero::get_nextLevelExp() const { return m_nextLevelExp; }

int Hero::get_lifePerLevel() const { return m_lifePerLevel; }

void Hero::set_currentExp(unsigned int t_currentExp)
{
    t_currentExp = m_currentExp;
}

void Hero::set_nextLevelExp(unsigned int t_nextLevelExp)
{
    t_nextLevelExp = m_nextLevelExp;
}

void Hero::set_lifePerLevel(uint8_t t_lifePerLevel)
{
    t_lifePerLevel = m_lifePerLevel;
}

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

std::string Hero::showStats() const
{
    std::stringstream stream;

    // Avoiding code repetition with lambda function.
    std::function<void (std::stringstream&, std::string, int)> showStat = 
        [] (std::stringstream& stream, const std::string& statName, int value)
    {
        stream << statName << ": " << std::noshowpos << value
            << std::showpos << " (" << modifier(value) << ")\n";
    };

    showStat(stream, "Strength", strength() );
    showStat(stream, "Dexterity", dexterity() );
    showStat(stream, "Constitution", constitution() );
    showStat(stream, "Inteligence", inteligence() );
    showStat(stream, "Wisdom", wisdom() );
    showStat(stream, "Charisma", charisma() );

    return stream.str();
}

std::string Hero::show() const
{
    std::stringstream stream;

    stream
        << "Level: " << static_cast<int>(m_level) << '\n'
        << "Experience: " << m_currentExp << "/"
            << m_nextLevelExp << "\n\n"
        << "Life: " << m_currentLife << '/' << m_maxLife << '\n'
        << "Armor class: " << armorClass() << "\n\n"
        << showStats() << '\n'
        << "Equipped weapon: " << ( m_equippedWeapon
                ? m_equippedWeapon->showWeapon()
                : m_naturalWeapon->showWeapon()
            ) << '\n'
        << "Equipped armor: " <<
            (m_equippedArmor ? m_equippedArmor->showArmor() : " None") << "\n\n"
        << "Equipped shield: " <<
             (m_equippedShield ? m_equippedShield->showShield() : "None");

    return stream.str();
}

std::string Hero::getIdAsString() const
{
    std::stringstream stream;

    stream << Character::getIdAsString() << " " << m_currentExp;

    if(m_equippedWeapon) stream << " " << m_equippedWeapon->getIdAsString();
    if(m_equippedShield) stream << " " << m_equippedShield->getIdAsString();
    if(m_equippedArmor) stream << " " << m_equippedShield->getIdAsString();

    return stream.str();
}