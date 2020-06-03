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

std::unique_ptr<Weapon>& Character::get_equippedWeapon()
{
   return m_equippedWeapon;
}

std::unique_ptr<Armor>& Character::get_equippedArmor()
{
   return m_equippedArmor;
}

std::unique_ptr<Shield>& Character::get_equippedShield()
{
    return m_equippedShield;
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
    m_equippedWeapon = std::make_unique<Weapon>(t_weapon);
}

void Character::set_equippedArmor(const Armor& t_armor)
{
    m_equippedArmor = std::make_unique<Armor>(t_armor);
}

void Character::set_equippedShield(const Shield& t_shield)
{
    m_equippedShield = std::make_unique<Shield>(t_shield);
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

short Character::dexterityModifier() const
{
    const short armorLimit = m_equippedArmor->get_maximumDexterity(),
        modifier = Sheet::modifier(m_dexterity);

    if(modifier > armorLimit) return armorLimit;

    return modifier;
}

int Character::armorClass() const
{   
    short dexterityModifier = modifier(m_dexterity);
   
    if(m_equippedArmor)
    {
        short auxiliary = 0;
        
        auxiliary = m_equippedArmor->get_maximumDexterity();
        if(dexterityModifier > auxiliary) dexterityModifier = auxiliary;
    }
    
    return 
        10 + (m_level / 2) + dexterityModifier
        + (m_equippedArmor ? m_equippedArmor->totalArmorClassBonus() : 0)
        + (m_equippedShield ? m_equippedShield->totalArmorClassBonus() : 0);
}

int Character::initiativeBonus() const
{
    return (m_level / 2) + dexterityModifier();
}

void Character::naturalWeapon()
{
    switch (m_race)
    {
        case Race::GNOLL:
        {
            m_naturalWeapon = std::make_unique<Weapon>
            (
                "Bite", 0u, 0.f, 0u, 1u, Dice::D6, 20u, 2u, DamageType::PIERCE,
                WeaponType::ONE_HANDED
            );
        } break;
        default:
        {
            m_naturalWeapon = std::make_unique<Weapon>
            (
                "Unarmed attack", 0u, 0.f, 0u, 1u, Dice::D3, 20u, 2u,
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