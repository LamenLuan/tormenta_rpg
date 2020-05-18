#include "../headers/character.hpp"

#include <memory>

Character::Character
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    Race t_race, unsigned short t_currentLife
)
:
    Sheet
    (
        std::move(t_name), t_strength, t_dexterity, t_constitution,
        t_inteligence, t_wisdom, t_charisma, t_level, t_maxLife, t_currentLife
    ),
    m_race(t_race)
{
    naturalWeapon();
}

Character::~Character() = default;

Race Character::get_race() const { return m_race; }

Weapon& Character::get_equippedWeapon()
{
    return *m_equippedWeapon;
}

Armor& Character::get_equippedArmor()
{
   return *m_equippedArmor;
}

Shield& Character::get_equippedShield()
{
    return *m_equippedShield;
}

void Character::set_strength(short t_strength)
{
    if(t_strength > 0) m_strength = t_strength;
}

void Character::set_race(Race t_race)
{
    if(m_race != t_race)
    {
        m_race = t_race;
        naturalWeapon();
    }
}

void Character::set_equippedWeapon(const Weapon& t_weapon)
{
    /*
    if
    (
        m_equippedShield &&
        (
            t_weapon.get_weaponType() == WeaponType::TWO_HANDED ||
            t_weapon.get_weaponType() == WeaponType::POLE_ARM_2H
        ) 
    )
    {
        m_inventory.addItem(*m_equippedShield);
        m_inventory.set_currentWeight(
            m_inventory.get_currentWeight() - m_equippedShield->get_weight()
        );
        m_equippedShield.reset();
    }
    if(m_equippedWeapon)
    {
        m_inventory.addItem(*m_equippedWeapon);
        m_inventory.set_currentWeight(
            m_inventory.get_currentWeight() - m_equippedWeapon->get_weight()
        );
    }
    */
    m_equippedWeapon = std::make_unique<Weapon>(t_weapon);
    /*
    m_inventory.set_currentWeight(
        m_inventory.get_currentWeight() + m_equippedWeapon->get_weight()
    );
    */
}

void Character::set_equippedArmor(const Armor& t_armor)
{
    /*
    if(m_equippedArmor)
    {
        m_inventory.addItem(*m_equippedArmor);
        m_inventory.set_currentWeight
        (
            m_inventory.get_currentWeight() - m_equippedArmor->get_weight()
        );
    }
    */
    m_equippedArmor = std::make_unique<Armor>(t_armor);
    /*
    m_inventory.set_currentWeight
    (
        m_inventory.get_currentWeight() + m_equippedArmor->get_weight()
    );
    */
}

void Character::set_equippedShield(const Shield& t_shield)
{
    /*
    if(m_equippedWeapon)
    {
        // Two ifs to avoid problems if m_equippedWeapon is null.
        if
        (
            m_equippedWeapon->get_weaponType() == WeaponType::TWO_HANDED ||
            m_equippedWeapon->get_weaponType() == WeaponType::POLE_ARM_2H
        )
        {
            m_inventory.addItem(*m_equippedWeapon);
            m_inventory.set_currentWeight
            (
                m_inventory.get_currentWeight() - m_equippedWeapon->get_weight()
            );
            m_equippedWeapon.reset();
        } // if
    } // if
    if(m_equippedShield)
    {
        m_inventory.addItem(*m_equippedShield);
        m_inventory.set_currentWeight
        (
            m_inventory.get_currentWeight() - m_equippedShield->get_weight()
        );
    }
    */
    m_equippedShield = std::make_unique<Shield>(t_shield);
    /*
    m_inventory.set_currentWeight
    (
        m_inventory.get_currentWeight() + m_equippedShield->get_weight()
    );
    */
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
        << get_charisma() << " " << static_cast<int>(m_race) << " "
        << m_maxLife << " " << m_currentLife;

    return stream.str();
}