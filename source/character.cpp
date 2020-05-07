#include "../headers/character.hpp"

#include <memory>

Character::Character()
    :
    Sheet(),
    m_backpack(m_strength)
{
    naturalWeapon();
}

Character::Character(std::string t_name, uint8_t t_strength,
        uint8_t t_dexterity, uint8_t t_constitution, uint8_t t_inteligence,
        uint8_t t_wisdom, uint8_t t_charisma, uint8_t t_level,
        unsigned short t_maxLife, Race t_race, unsigned int t_coins)
    :
    Sheet(std::move(t_name), t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, t_level, t_maxLife), m_race(t_race),
        m_backpack(m_strength), m_coins(t_coins)
{
    naturalWeapon();
    m_backpack.set_currentWeight
        (m_backpack.get_currentWeight() + (0.01f * m_coins) );
}

Character::~Character() = default;

Race Character::get_race() const { return m_race; }

Backpack& Character::get_backpack() { return m_backpack; }

Weapon& Character::get_equippedWeapon()
{
    if(m_equippedWeapon) return *m_equippedWeapon;
    else throw NullObject();
}

Armor& Character::get_equippedArmor()
{
    if(m_equippedArmor) return *m_equippedArmor;
    else throw NullObject();
}

Shield& Character::get_equippedShield()
{
    if(m_equippedShield) return *m_equippedShield;
    else throw NullObject();
}

void Character::set_strength(short t_strength)
{
    // Validating the attribution of a different number is worth because
    // another method is called.
    if(t_strength > 0 && m_strength != t_strength)
    {
        m_strength = t_strength;
        m_backpack.set_capacity( strength() * 10.f );
    }
}

unsigned int Character::get_coins() const { return m_coins; }

void Character::set_race(Race t_race)
{
    if(m_race != t_race)
    {
        m_race = t_race;
        naturalWeapon();
    }
}

void Character::set_backpack(const Backpack& t_backpack)
{
    m_backpack = t_backpack;
}

void Character::set_equippedWeapon(const Weapon& t_weapon)
{
    if
    (
        m_equippedShield &&
        (
            t_weapon.get_weaponType() == WeaponType::TWO_HANDED ||
            t_weapon.get_weaponType() == WeaponType::POLE_ARM_2H
        ) 
    )
    {
        m_backpack.addItem(*m_equippedShield);
        m_backpack.set_currentWeight(
            m_backpack.get_currentWeight() - m_equippedShield->get_weight()
        );
        m_equippedShield.reset();
    }
    if(m_equippedWeapon)
    {
        m_backpack.addItem(*m_equippedWeapon);
        m_backpack.set_currentWeight(
            m_backpack.get_currentWeight() - m_equippedWeapon->get_weight()
        );
    }
    m_equippedWeapon = std::make_unique<Weapon>(t_weapon);
    m_backpack.set_currentWeight(
        m_backpack.get_currentWeight() + m_equippedWeapon->get_weight()
    );
}

void Character::set_equippedArmor(const Armor& t_armor)
{
    if(m_equippedArmor)
    {
        m_backpack.addItem(*m_equippedArmor);
        m_backpack.set_currentWeight
        (
            m_backpack.get_currentWeight() - m_equippedArmor->get_weight()
        );
    }
    m_equippedArmor = std::make_unique<Armor>(t_armor);
    m_backpack.set_currentWeight
    (
        m_backpack.get_currentWeight() + m_equippedArmor->get_weight()
    );
}

void Character::set_equippedShield(const Shield& t_shield)
{
    if(m_equippedWeapon)
    {
        // Two ifs to avoid problems if m_equippedWeapon is null.
        if
        (
            m_equippedWeapon->get_weaponType() == WeaponType::TWO_HANDED ||
            m_equippedWeapon->get_weaponType() == WeaponType::POLE_ARM_2H
        )
        {
            m_backpack.addItem(*m_equippedWeapon);
            m_backpack.set_currentWeight
            (
                m_backpack.get_currentWeight() - m_equippedWeapon->get_weight()
            );
            m_equippedWeapon.reset();
        } // if
    } // if
    if(m_equippedShield)
    {
        m_backpack.addItem(*m_equippedShield);
        m_backpack.set_currentWeight
        (
            m_backpack.get_currentWeight() - m_equippedShield->get_weight()
        );
    }
    m_equippedShield = std::make_unique<Shield>(t_shield);
    m_backpack.set_currentWeight
    (
        m_backpack.get_currentWeight() + m_equippedShield->get_weight()
    );
}

void Character::set_coins(unsigned int t_coins)
{
    if(t_coins != static_cast<int>(m_coins) && t_coins >= 0)
    {
        // Subtracting the weight of the actual quantity.
        m_backpack.set_currentWeight
            (m_backpack.get_currentWeight() - (m_coins * 0.01f));
        m_coins = t_coins;
        // Adding the weight of the new quantity.
        m_backpack.set_currentWeight
            (m_backpack.get_currentWeight() + (m_coins * 0.01f));
    }
}

std::string Character::raceName() const
{
    switch (m_race)
    {
        case Race::DWARF: return "Dwarf"; break;
        case Race::ELF: return "Elf"; break;
        case Race::GNOLL: return "Gnoll"; break;
        case Race::GOBLIN: return "Goblin"; break;
        case Race::HUMAN: return "Human"; break;
    }

    return "";
}

int Character::dexterity() const
{
    int dexterity = m_dexterity;

    if(m_equippedShield) dexterity += m_equippedShield->get_armorPenalty();
    if(m_equippedArmor)
    {
        dexterity += m_equippedArmor->get_armorPenalty();
        if(modifier(dexterity) >  m_equippedArmor->get_maximumDexterity() )
            dexterity = m_equippedArmor->get_maximumDexterity();
    }

    return dexterity;
}

int Character::armorClass() const
{
    return 10 + (m_level / 2)
        + modifier(dexterity() )
        + (m_equippedArmor ? m_equippedArmor->get_armorClassBonus() : 0)
        + (m_equippedShield ? m_equippedShield->get_armorClassBonus() : 0);
}

int Character::initiativeBonus() const
{
    return (m_level / 2) + dexterity();
}

void Character::naturalWeapon()
{
    switch (m_race)
    {
        case Race::GNOLL:
        {
            m_naturalWeapon = std::make_unique<Weapon>
            (
                "Bite", 0, 0.f, 1, Dice::D6, 20, 2, DamageType::PIERCE,
                WeaponType::ONE_HANDED
            );
        } break;
        default:
        {
            m_naturalWeapon = std::make_unique<Weapon>
            (
                "Unarmed attack", 0, 0.f, 1, Dice::D3, 20, 2,
                DamageType::BLUDGEON, WeaponType::ONE_HANDED
            );
        } break;
    }
}

std::string Character::show() const
{
    std::stringstream stream;

    stream << m_name;

    return stream.str();
}

std::string Character::getIdAsString() const
{
    std::stringstream stream;
    std::string name(m_name);

    Utils::underscoreSpaces(name);

    stream << name << " " << get_strength() << " "
        << get_dexterity() << " " << get_constitution() << " "
        << get_inteligence() << " " << get_wisdom() << " "
        << get_charisma() << " " << get_level() << " "
        << static_cast<int>(m_race) << " "  << get_coins() << " "
        << m_currentLife;

    return stream.str();
}