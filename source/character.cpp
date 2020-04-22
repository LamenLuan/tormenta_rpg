#include "../headers/character.hpp"

Character::Character()
    :
    Sheet(),
    m_inventory(m_strength)
{
    naturalWeapon();
}

Character::Character(std::string t_name, uint8_t t_strength,
        uint8_t t_dexterity, uint8_t t_constitution, uint8_t t_inteligence,
        uint8_t t_wisdom, uint8_t t_charisma, uint8_t t_level,
        unsigned short t_maxLife, Race t_race, int t_coins)
    :
    Sheet(t_name, t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, t_level, t_maxLife), m_race(t_race),
        m_inventory(m_strength), m_coins(t_coins)
{
    naturalWeapon();
    m_inventory.set_currentWeight
        (m_inventory.get_currentWeight() + (m_coins * 0.01f) );
}

Character::~Character()
{
    m_equipedWeapon.release();
}

Race Character::get_race() const { return m_race; }

Inventory& Character::get_inventory() { return m_inventory; }

Weapon& Character::get_equipedWeapon()
{
    if(m_equipedWeapon) return *m_equipedWeapon;
    else throw NullObject();
}

Armor Character::get_equipedArmor()
{
    if(m_equipedArmor) return *m_equipedArmor;
    else throw NullObject();
}

Shield Character::get_equipedShield()
{
    if(m_equipedShield) return *m_equipedShield;
    else throw NullObject();
}

void Character::set_strength(short t_strength)
{
    if(t_strength > 0)
    {
        m_strength = t_strength;
        m_inventory.set_capacity( strength() );
    }
}

unsigned int Character::get_coins() const { return m_coins; }

void Character::set_race(Race t_race) { m_race = t_race; }

void Character::set_inventory(Inventory& t_inventory)
{
    m_inventory = t_inventory;
}

void Character::set_equipedWeapon(Weapon& t_weapon)
{
    if(m_equipedWeapon.get() != &m_naturalWeapon)
    {
        m_inventory.addItem(*m_equipedWeapon);
    }
    m_equipedWeapon.reset(&t_weapon);
}

void Character::set_equipedArmor(Armor& t_armor)
{
    if(m_equipedArmor.get() != nullptr)
    {
        m_inventory.addItem(*m_equipedArmor);
    }
    m_equipedArmor.reset(&t_armor);
}

void Character::set_equipedShield(Shield& t_shield)
{
    if(m_equipedShield.get() != nullptr)
    {
        m_inventory.addItem(*m_equipedShield);
    }
    m_equipedShield.reset(&t_shield);
}

void Character::set_coins(int t_coins)
{
    if(t_coins != static_cast<int>(m_coins) && t_coins >= 0)
    {
        // Subtracting the weight of the actual quantity.
        m_inventory.set_currentWeight
            (m_inventory.get_currentWeight() - (m_coins * 0.01f));
        m_coins = t_coins;
        // Adding the weight of the new quantity.
        m_inventory.set_currentWeight
            (m_inventory.get_currentWeight() + (m_coins * 0.01f));
    }
}

const std::string Character::raceName() const
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

short Character::dexterity() const
{
    register short dexterity = m_dexterity;

    if(m_equipedShield) dexterity += m_equipedShield->get_armorPenalty();
    if(m_equipedArmor)
    {
        dexterity += m_equipedArmor->get_armorPenalty();
        if(modifier(dexterity) >  m_equipedArmor->get_maximumDexterity() )
            dexterity = m_equipedArmor->get_maximumDexterity();
    }

    return dexterity;
}

short Character::armorClass() const
{
    return 10 + (m_level / 2)
        + modifier(dexterity() )
        + (m_equipedArmor ? m_equipedArmor->get_armorClassBonus() : 0)
        + (m_equipedShield ? m_equipedShield->get_armorClassBonus() : 0);
}

short Character::initiativeBonus() const
{
    return (m_level / 2) + dexterity();
}

void Character::naturalWeapon()
{
    switch (m_race)
    {
        case Race::GNOLL:
        {
            m_naturalWeapon = 
                Weapon("Bite", 0, 0.f, 1, Dice::D6, 20, 2, DamageType::PIERCE);
        } break;
        default:
        {
            m_naturalWeapon =
                Weapon("Unarmed attack", 0, 0.f, 1, Dice::D3, 20, 2,
                    DamageType::BLUDGEON);
        } 
    }
}

const std::string Character::show() const
{
    std::stringstream stream;

    stream
        << "Name: " << m_name << '\n'
        << "Race: " << raceName() << '\n'
        << "Level: " << static_cast<int>(m_level) << '\n'
        << "Life: " << m_currentLife << '/' << m_maxLife << '\n'
        << "Armor class: " << std::showpos << armorClass() << "\n\n"
        << showStats() << "\n\n"
        << "Inventory: " << std::fixed << std::setprecision(2) << std::noshowpos
            << m_inventory.get_currentWeight() << "/"
            << m_inventory.get_capacity() << "kg" << "\n\n"
        << "Equiped weapon: " << m_equipedWeapon->showWeapon() << "\n\n"
        << "Equiped armor: " <<
            (m_equipedArmor ? m_equipedArmor->showArmor() : " None") << "\n\n"
        << "Equiped shield: " <<
             (m_equipedShield ? m_equipedShield->showShield() : "None");

    return stream.str();
}

std::string Character::getIdAsString() const
{
    std::stringstream stream;

    stream << m_name << " " << get_strength() << " "
        << get_dexterity() << " " << get_constitution() << " "
        << get_inteligence() << " " << get_wisdom() << " "
        << get_charisma() << " " << get_level() << " "
        << m_currentLife <<  " " << " " << raceName() << " " << get_coins();

    return stream.str();
}