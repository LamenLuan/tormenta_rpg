#include "../headers/weapon.hpp"

Weapon::Weapon
(
    unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
    uint8_t t_criticalMultiplier, DamageType t_Damagetype,
    WeaponType t_weaponType
)
    :
    MagicalItem(),
    m_damage(t_quantity, t_dice), m_minCriticalDice(t_minimumCriticalDice),
    m_criticalMultiplier(t_criticalMultiplier), m_damageType(t_Damagetype),
    m_weaponType(t_weaponType)
{
}

Weapon::Weapon
(
    std::string t_name, unsigned int t_price, float t_weight,
    unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
    uint8_t t_criticalMultiplier, DamageType t_Damagetype,
    WeaponType t_weaponType
)
    :
    Item(std::move(t_name), t_price, t_weight),
    m_damage(t_quantity, t_dice), m_minCriticalDice(t_minimumCriticalDice),
    m_criticalMultiplier(t_criticalMultiplier), m_damageType(t_Damagetype),
    m_weaponType(t_weaponType)
{
}

Weapon::Weapon
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, unsigned short t_quantity, Dice t_dice,
    uint8_t t_minimumCriticalDice, uint8_t t_criticalMultiplier,
    DamageType t_Damagetype, WeaponType t_weaponType
)
    :
    Item(std::move(t_name), t_price, t_weight),
    MagicalItem(t_magicalLevel),
    m_damage(t_quantity, t_dice), m_minCriticalDice(t_minimumCriticalDice),
    m_criticalMultiplier(t_criticalMultiplier), m_damageType(t_Damagetype),
    m_weaponType(t_weaponType)
{
}

Weapon::~Weapon() = default;

RollSet &Weapon::get_damage() { return m_damage; }

unsigned short Weapon::get_minCriticalDice() const { return m_minCriticalDice; }

unsigned short Weapon::get_criticalMultiplier() const
{
    return m_criticalMultiplier;
}

DamageType Weapon::get_damageType() const { return m_damageType; }

WeaponType Weapon::get_weaponType() const { return m_weaponType; }

void Weapon::set_damage(const RollSet& t_damage) { m_damage = t_damage; }

void Weapon::set_minCriticalDice(uint8_t t_minCriticalDice)
{
    m_minCriticalDice = t_minCriticalDice;
}

void Weapon::set_criticalMultiplier(uint8_t t_criticalMultiplier)
{
    m_criticalMultiplier = t_criticalMultiplier;
}

void Weapon::set_damageType(DamageType t_damageType)
{
    m_damageType = t_damageType;
}

void Weapon::set_weaponType(WeaponType t_weaponType)
{
    m_weaponType = t_weaponType;
}

std::string Weapon::showDamageType() const
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

std::string Weapon::showWeaponType() const
{
    switch(m_weaponType)
    {
        case WeaponType::LIGHT : return "Light"; break;
        case WeaponType::ONE_HANDED : return "One-Handed"; break;
        case WeaponType::TWO_HANDED : return "Two-Handed"; break;
        case WeaponType::POLE_ARM_1H : return "Pole arm / One-Handed"; break;
        default : return "Pole arm / Two-handed"; break;
    }
}

std::string Weapon::weaponInfo() const
{
    std::stringstream stream;

    stream
        << "Weapon Type: " << showWeaponType() << '\n'
        << "Damage: " << m_damage.show();

    if( get_magicalLevel() ) stream << " (+" << get_magicalLevel() << ')';
    
    stream
        << '\n' << "Critical: " << get_minCriticalDice() <<
            (m_minCriticalDice < 20u ? "-20" : "") << '/' <<
            get_criticalMultiplier() << "x\n"
        << "Damage Type: " << showDamageType() << '\n';

    return stream.str();
}

std::string Weapon::showWeapon() const
{
    std::stringstream stream;

    stream << showName() << '\n' << weaponInfo();

    return stream.str();
}

std::string Weapon::show() const
{
    std::stringstream stream;

    stream << Item::show() << weaponInfo();

    return stream.str();
}

std::string Weapon::weaponId() const
{
    std::stringstream stream;
    
    stream << m_damage.get_quantity() << " "
        << static_cast<short>( m_damage.get_dice() ) << " "
        << get_minCriticalDice() << " " << get_criticalMultiplier() << " "
        << static_cast<short>(m_damageType) << " "
        << static_cast<short>(m_weaponType);

    return stream.str();
}

std::string Weapon::getIdAsString() const
{
    std::stringstream stream;

    stream << "W " << magicalItemId() << " " << weaponId();

    return stream.str();
}