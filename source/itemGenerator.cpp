#include "../headers/itemGenerator.hpp"

Weapon* ItemGenerator::generateWeapon(size_t t_index)
{
    const std::array<Weapon, 18> items =
        {
            Weapon("Dagger", 2u, 0.5f, 1u, Dice::D4, 19u, 2u, DamageType::PIERCE, WeaponType::ONE_HANDED),
            Weapon("Halberd", 10u, 6.f, 1u, Dice::D10, 20u, 3u, DamageType::SLASH, WeaponType::POLE_ARM_2H),
            Weapon("Club", 0u, 1.5f, 1u, Dice::D6, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
            Weapon("Short Sword", 10u, 1.f, 1u, Dice::D6, 19u, 2u, DamageType::SLASH, WeaponType::LIGHT),
            Weapon("Great Sword", 50u, 4.f, 2u, Dice::D6, 19u, 2u, DamageType::SLASH, WeaponType::TWO_HANDED),
            Weapon("Long Sword", 15u, 2.f, 1u, Dice::D8, 19u, 2u, DamageType::SLASH, WeaponType::ONE_HANDED),
            Weapon("Rapier", 20u, 1.f, 1u, Dice::D6, 18u, 2u, DamageType::PIERCE, WeaponType::ONE_HANDED),
            Weapon("Sickle", 18u, 5.f, 2u, Dice::D4, 20u, 4u, DamageType::SLASH, WeaponType::TWO_HANDED),
            Weapon("Spear", 2u, 1.5f, 1u, Dice::D6, 20u, 2u, DamageType::PIERCE, WeaponType::POLE_ARM_1H),
            Weapon("Mace", 12u, 6.f, 1u, Dice::D8, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
            Weapon("Hatchet", 6u, 2.f, 1u, Dice::D6, 20u, 3u, DamageType::SLASH, WeaponType::ONE_HANDED),
            Weapon("Battle Axe", 10u, 3.f, 1u, Dice::D8, 20u, 3u, DamageType::SLASH, WeaponType::ONE_HANDED),
            Weapon("Great Axe", 20u, 6.f, 1u, Dice::D12, 20u, 3u, DamageType::SLASH, WeaponType::TWO_HANDED),
            Weapon("Flail", 8u, 2.5f, 1u, Dice::D8, 20u, 2u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
            Weapon("Hammer", 1u, 1.f, 1u, Dice::D6, 20u, 2u, DamageType::BLUDGEON, WeaponType::LIGHT),
            Weapon("War Hammer", 12u, 2.5f, 1u, Dice::D8, 20u, 3u, DamageType::BLUDGEON, WeaponType::ONE_HANDED),
            Weapon("Pickaxe", 8u, 3.f, 1u, Dice::D6, 20u, 4u, DamageType::PIERCE, WeaponType::ONE_HANDED),
            Weapon("Giant Club", 0u, 4.f, 1u, Dice::D10, 20u, 2u, DamageType::BLUDGEON, WeaponType::TWO_HANDED),
        };

    return new Weapon(items[t_index]);
}