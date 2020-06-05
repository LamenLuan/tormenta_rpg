#include "../headers/shield.hpp"

Shield::Shield
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, unsigned short t_quantity, Dice t_dice,
    uint8_t t_minimumCriticalDice, uint8_t t_criticalMultiplier,
    DamageType t_damageType, int8_t t_armorClassBonus, int8_t t_armorPenalty
)
    :
    Weapon
    (
        std::move(t_name), t_price, t_weight, t_magicalLevel, t_quantity, t_dice,
        t_minimumCriticalDice, t_criticalMultiplier, t_damageType,
        WeaponType::ONE_HANDED
    ),
    m_armorClassBonus(t_armorClassBonus), m_armorPenalty(t_armorPenalty)
{
}

Shield::~Shield() = default;

short Shield::get_armorClassBonus() const { return m_armorClassBonus; }
short Shield::get_armorPenalty() const { return m_armorPenalty; }

void Shield::set_armorClassBonus(int8_t t_armorClassBonus)
{
    m_armorClassBonus = t_armorClassBonus;
}
void Shield::set_armorPenalty(int8_t t_armorPenalty)
{
    m_armorPenalty = t_armorPenalty;
}

short Shield::totalArmorClassBonus() const
{
    return m_armorClassBonus + get_magicalLevel();
}

std::string Shield::shieldInfo() const
{
    std::stringstream stream;

    stream << std::showpos 
        << "Armor class bonus: " << get_armorClassBonus();

    if( get_magicalLevel() ) stream << " (+" << get_magicalLevel() << ')';
    
    stream << '\n' << "Armor penalty: " << get_armorPenalty();

    return stream.str();
}

std::string Shield::showShield() const
{
    std::stringstream stream;

    stream << showName() << '\n' << shieldInfo();

    return stream.str();
}

std::string Shield::show() const
{
    std::stringstream stream;

    stream << Weapon::show() << shieldInfo() << '\n' << weaponInfo() << '\n';

    return stream.str();
}

std::string Shield::shieldId() const
{
    std::stringstream stream;

    stream << get_armorClassBonus() << " " << get_armorPenalty();

    return stream.str();
}

std::string Shield::getIdAsString() const
{
    std::stringstream stream;

    stream << "S " << equipableItemId() << " " << weaponId()
        << " " << shieldId();

    return stream.str();
}