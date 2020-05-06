#include "../headers/weapon.hpp"

Weapon::Weapon() : Item()
{
}

Weapon::Weapon(std::string t_name, unsigned int t_price, float t_weight,
    unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
    uint8_t t_criticalMultiplier, DamageType t_weaponType)
    : 
    Item(std::move(t_name), t_price, t_weight),
    m_damage(t_quantity, t_dice), m_minCriticalDice(t_minimumCriticalDice),
    m_criticalMultiplier(t_criticalMultiplier), m_damageType(t_weaponType)
{
}

Weapon::~Weapon() = default;

RollSet &Weapon::get_damage() { return m_damage; }

DamageType Weapon::get_damageType() const { return m_damageType; }

int Weapon::get_minCriticalDice() const { return m_minCriticalDice; }

int Weapon::get_criticalMultiplier() const
{
    return m_criticalMultiplier;
}

void Weapon::set_damage(const RollSet& t_damage) { m_damage = t_damage; }

void Weapon::set_damageType(DamageType t_type) { m_damageType = t_type; }

void Weapon::set_minCriticalDice(uint8_t t_minCriticalDice)
{
    m_minCriticalDice = t_minCriticalDice;
}

void Weapon::set_criticalMultiplier(uint8_t t_criticalMultiplier)
{
    m_criticalMultiplier = t_criticalMultiplier;
}

std::string Weapon::showWeaponType() const
{
    switch (m_damageType)
    {
    case DamageType::ACID : return "Acid"; break;
    case DamageType::BLUDGEON : return "Bludgeon"; break;
    case DamageType::FIRE : return "Fire"; break;
    case DamageType::PIERCE : return "Pierce"; break;
    case DamageType::SLASH : return "Slash"; break;
    default : return "Special"; break;
    }
}

std::string Weapon::weaponInfo() const
{
    std::stringstream stream;

    stream
        << "Damage: " << m_damage.show() << '\n'
        << "Critical: " << get_minCriticalDice() <<
            (m_minCriticalDice < 20u ? "-20" : "") << '/' <<
            get_criticalMultiplier() << "x\n"
        << "Damage Type: " << showWeaponType();

    return stream.str();
}

std::string Weapon::showWeapon() const
{
    std::stringstream stream;

    stream << m_name << '\n' << weaponInfo();

    return stream.str();
}

std::string Weapon::show() const
{
    std::stringstream stream;

    stream << Item::show() << weaponInfo() << '\n';

    return stream.str();
}

std::string Weapon::weaponId() const
{
    std::stringstream stream;
    
    stream << m_damage.get_quantity() << " "
        << static_cast<short>( m_damage.get_dice() ) << " "
        << get_minCriticalDice() << " " << get_criticalMultiplier() << " "
        << static_cast<short>(m_damageType);

    return stream.str();
}

std::string Weapon::getIdAsString() const
{
    std::stringstream stream;

    stream << "W " << itemId() << " " << weaponId();

    return stream.str();
}