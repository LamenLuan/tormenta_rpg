#include "../headers/itemGenerator.hpp"

Item* ItemGenerator::generateWeapon(size_t t_index)
{
    const std::array<Weapon, weaponQuantity> items =
    {
        Weapon("Short Sword", 10u, 1.f, 1u, Dice::D6, 19u, 2u, DamageType::SLASH, WeaponType::LIGHT),
        Weapon("Hammer", 1u, 1.f, 1u, Dice::D6, 20u, 2u, DamageType::BLUDGEON, WeaponType::LIGHT),

        Weapon("Battle Axe", 10u, 3.f, 1u, Dice::D8, 20u, 3u, DamageType::SLASH, WeaponType::ONE_HANDED),
        Weapon("Club", 0u, 1.5f, 1u, Dice::D6, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
        Weapon("Dagger", 2u, 0.5f, 1u, Dice::D4, 19u, 2u, DamageType::PIERCE, WeaponType::ONE_HANDED),
        Weapon("Flail", 8u, 2.5f, 1u, Dice::D8, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
        Weapon("Hatchet", 6u, 2.f, 1u, Dice::D6, 20u, 3u, DamageType::SLASH, WeaponType::ONE_HANDED),
        Weapon("Long Sword", 15u, 2.f, 1u, Dice::D8, 19u, 2u, DamageType::SLASH, WeaponType::ONE_HANDED),
        Weapon("Mace", 12u, 6.f, 1u, Dice::D8, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
        Weapon("Pickaxe", 8u, 3.f, 1u, Dice::D6, 20u, 4u, DamageType::PIERCE, WeaponType::ONE_HANDED),
        Weapon("Rapier", 20u, 1.f, 1u, Dice::D6, 18u, 2u, DamageType::PIERCE, WeaponType::ONE_HANDED),
        Weapon("War Hammer", 12u, 2.5f, 1u, Dice::D8, 20u, 3u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),

        Weapon("Giant Club", 0u, 4.f, 1u, Dice::D10, 20u, 2u, DamageType::BLUDGEON, WeaponType::TWO_HANDED),
        Weapon("Great Axe", 20u, 6.f, 1u, Dice::D12, 20u, 3u, DamageType::SLASH, WeaponType::TWO_HANDED),
        Weapon("Great Sword", 50u, 4.f, 2u, Dice::D6, 19u, 2u, DamageType::SLASH, WeaponType::TWO_HANDED),
        Weapon("Sickle", 18u, 5.f, 2u, Dice::D4, 20u, 4u, DamageType::SLASH, WeaponType::TWO_HANDED),

        Weapon("Spear", 2u, 1.5f, 1u, Dice::D6, 20u, 2u, DamageType::PIERCE, WeaponType::POLE_ARM_1H),

        Weapon("Halberd", 10u, 6.f, 1u, Dice::D10, 20u, 3u, DamageType::SLASH, WeaponType::POLE_ARM_2H)
    };

    return new Weapon(items[t_index]);
}

Item* ItemGenerator::generateArmor(size_t t_index)
{
    const std::array<Armor, armorQuantity> items = 
    {
        Armor("Chain Shirt", 100u, 12.f, 4u, 2u, 4u, ArmorType::LIGHT),
        Armor("Leather Armor", 10u, 7.f, 2u, 0u, 6u, ArmorType::LIGHT),
        Armor("Padded Armor", 5u, 5.f, 1u, 0u, 8u, ArmorType::LIGHT),
        Armor("Studded Leather Armor", 25u, 10.f, 3u, 1u, 5u, ArmorType::LIGHT),

        Armor("Breastplate", 200u, 15.f, 5u, 4u, 3u, ArmorType::MEDIUM),
        Armor("Chain Mail Armor", 150u, 20.f, 5u, 3u, 2u, ArmorType::MEDIUM),
        Armor("Hide Armor", 15u, 12.f, 3u, 2u, 4u, ArmorType::MEDIUM),
        Armor("Scale Mail Armor", 50u, 15.f, 4u, 3u, 3u, ArmorType::MEDIUM),

        Armor("Full Plate Armor", 1500u, 25.f, 8u, 5u, 1u, ArmorType::HEAVY),
        Armor("Half Plate Armor", 600u, 22.f, 7u, 4u, 1u, ArmorType::HEAVY),
        Armor("Ring Mail Armor", 30u, 13.f, 4u, 3u, 1u, ArmorType::HEAVY),
        Armor("Splint Armor", 200u, 20.f, 6u, 4u, 0u, ArmorType::HEAVY)
    };

    return new Armor(items[t_index]);
}

Item* ItemGenerator::generateShield(size_t t_index)
{
    const std::array<Shield, shieldQuantity> items = 
    {
        Shield("Light Shield", 5u, 3.f, 1u, 1u, 1u, Dice::D4),
        Shield("Heavy Shield", 15u, 7.f, 2u, 2u, 1u, Dice::D6)
    };

    return new Shield(items[t_index]);
}

Item* ItemGenerator::generateDefenceItem(size_t t_index)
{
    if(t_index < armorQuantity)
        return generateArmor(t_index);
    else
        return generateShield(t_index - armorQuantity);
}

Item* ItemGenerator::generateItem(size_t t_index)
{
    if(t_index < weaponQuantity)
        return generateWeapon(t_index);
    else
        return generateDefenceItem(t_index - weaponQuantity);
}
