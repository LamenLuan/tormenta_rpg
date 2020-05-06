#include "../headers/fileLoader.hpp"

template<typename T> T* FileLoader::loadHero(std::istringstream& input)
{
    unsigned short strength, dexterity, constitution, inteligence, wisdom, 
        charisma, level, currentLife, race;
    int coins;
    unsigned int currentExp;
    std::string name;

    input >> name >> strength >> dexterity >> constitution
            >> inteligence >> wisdom >> charisma >> level >> race >> coins
            >> currentLife >> currentExp;

    Utils::ununderscoreSpaces(name);

    return new T
    (
        name, strength, dexterity, constitution, inteligence, wisdom, charisma,
        level, static_cast<Race>(race), coins, currentLife, currentExp
    );
}
template Warrior* FileLoader::loadHero<Warrior>(std::istringstream& input);

void FileLoader::loadItem
(
    Backpack& backpack, std::istringstream& input, char itemClass
)
{
    switch (itemClass)
    {
        case 'I' : backpack.addItem( loadItem(input) ); break;
        case 'W' : backpack.addItem( loadWeapon(input) ); break;
        case 'A' : backpack.addItem( loadArmor(input) ); break;
        case 'S' : backpack.addItem( loadShield(input) ); break;
    }
}

Item FileLoader::loadItem(std::istringstream& input)
{
    int price;
    float weight;
    std::string name;

    input >> name >> price >> weight;

    Utils::ununderscoreSpaces(name);

    return Item(name, price, weight);
}

Weapon FileLoader::loadWeapon(std::istringstream& input)
{
    unsigned short minCriticalDice, criticalMultiplier;
    short diceQuantity, diceNumber, damageType;
    int price;
    float weight;
    std::string name;

    input >> name >> price >> weight >> diceQuantity >> diceNumber
        >> minCriticalDice >> criticalMultiplier >> damageType;

    Utils::ununderscoreSpaces(name);

    return Weapon
    (
        name, price, weight, diceQuantity, static_cast<Dice>(diceNumber),
        minCriticalDice, criticalMultiplier,
        static_cast<DamageType>(damageType)
    );
}

Armor FileLoader::loadArmor(std::istringstream& input)
{
    int price, armorClassBonus, armorPenalty, maximumDexterity;
    float weight;
    std::string name;

    input >> name >> price >> weight >> armorClassBonus >> armorPenalty
        >> maximumDexterity;

    Utils::ununderscoreSpaces(name);

    return Armor
    (
        name, price, weight, armorClassBonus, armorPenalty, maximumDexterity
    );
}

Shield FileLoader::loadShield(std::istringstream& input)
{
    unsigned short minCriticalDice, criticalMultiplier;
    short diceQuantity, diceNumber, damageType;
    int price, armorClassBonus, armorPenalty;
    float weight;
    std::string name;

    input >> name >> price >> weight >> diceQuantity >> diceNumber
        >> minCriticalDice >> criticalMultiplier >> damageType
        >> armorClassBonus >> armorPenalty;

    Utils::ununderscoreSpaces(name);

    return Shield
    (
        name, price, weight, diceQuantity, static_cast<Dice>(diceNumber),
        minCriticalDice, criticalMultiplier,
        static_cast<DamageType>(damageType), armorClassBonus, armorPenalty
    );
}