#include "../headers/party.hpp"

Party::Party()
:
    m_inventory(), m_heroes{}
{
}

Party::~Party() = default;

void Party::set_coins(unsigned int t_coins)
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

unsigned int Party::get_coins()
{
    return m_coins;
}

Inventory& Party::get_inventory()
{
    return m_inventory;
}

std::array<std::unique_ptr<Hero>, 4>& Party::get_heroes()
{
    return m_heroes;
}

void Party::equipWeapon(Hero& t_hero, size_t t_index)
{
    const Weapon& weapon = *dynamic_cast<Weapon*>
    (
        m_inventory.get_items()[t_index]
    );

    std::unique_ptr<Weapon>& equippedWeapon = t_hero.get_equippedWeapon();
    std::unique_ptr<Shield>& equippedShield = t_hero.get_equippedShield();

    if
    (
        equippedShield &&
        (
            weapon.get_weaponType() == WeaponType::TWO_HANDED ||
            weapon.get_weaponType() == WeaponType::POLE_ARM_2H
        ) 
    )
    {
        m_inventory.addItem(*equippedShield);
        equippedShield.reset();
    }

    if(equippedWeapon) m_inventory.addItem(*equippedWeapon);

    t_hero.set_equippedWeapon(weapon);

    m_inventory.removeItem(t_index);
}

void Party::equipArmor(Hero& t_hero, size_t t_index)
{
    const Armor& armor = *dynamic_cast<Armor*>
    (
        m_inventory.get_items()[t_index]
    );

    std::unique_ptr<Armor>& equippedArmor = t_hero.get_equippedArmor();

    if(equippedArmor) m_inventory.addItem(*equippedArmor);

    t_hero.set_equippedArmor(armor);

    m_inventory.removeItem(t_index);
}

void Party::equipShield(Hero& t_hero, size_t t_index)
{
    const Shield& shield = *dynamic_cast<Shield*>
    (
        m_inventory.get_items()[t_index]
    );

    std::unique_ptr<Weapon>& equippedWeapon = t_hero.get_equippedWeapon();
    std::unique_ptr<Shield>& equippedShield = t_hero.get_equippedShield();
    
    if(equippedWeapon)
    {
        // Two ifs to avoid problems if equippedWeapon is null.
        if
        (
            equippedWeapon->get_weaponType() == WeaponType::TWO_HANDED ||
            equippedWeapon->get_weaponType() == WeaponType::POLE_ARM_2H
        )
        {
            m_inventory.addItem(*equippedWeapon);
            equippedWeapon.reset();
        } // if
    } // if

    if(equippedShield) m_inventory.addItem(*equippedShield);

    t_hero.set_equippedShield(shield);

    m_inventory.removeItem(t_index);
}