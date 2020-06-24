#include "../headers/shield.hpp"

Shield::Shield
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, uint8_t t_armorClassBonus,
    uint8_t t_armorPenalty, unsigned short t_quantity, Dice t_dice,
    uint8_t t_minimumCriticalDice, uint8_t t_criticalMultiplier
)
    :
    Item(std::move(t_name), t_price, t_weight),
    MagicalItem(t_magicalLevel),
    DefenceItem(t_armorClassBonus, t_armorPenalty),
    Weapon
    (
        t_quantity, t_dice, t_minimumCriticalDice, t_criticalMultiplier,
        DamageType::BLUDGEON, WeaponType::ONE_HANDED
    )
{
}

Shield::~Shield() = default;

std::string Shield::showShield() const
{
    std::stringstream stream;

    stream << showName() << '\n' << defenceItemInfo();

    return stream.str();
}

std::string Shield::show() const
{
    std::stringstream stream;

    stream << Item::show() << defenceItemInfo() << '\n'
        << weaponInfo() << '\n';

    return stream.str();
}

std::string Shield::getIdAsString() const
{
    std::stringstream stream;

    stream << "S " << defenceItemId() << " " << weaponId();

    return stream.str();
}