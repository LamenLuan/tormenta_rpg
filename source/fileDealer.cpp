#include "../headers/fileDealer.hpp"

template<typename T> T* FileDealer::loadHero(std::istringstream& input)
{
    unsigned short strength, dexterity, constitution, inteligence, wisdom, 
        charisma, race, maxLife, currentLife;
    unsigned int currentExp;
    std::string name;

    input >> name >> strength >> dexterity >> constitution
            >> inteligence >> wisdom >> charisma >> race >> maxLife
            >> currentLife >> currentExp;

    Utils::ununderscoreSpaces(name);

    return new T
    (
        name, strength, dexterity, constitution, inteligence, wisdom, charisma,
        static_cast<Race>(race), maxLife, currentLife, currentExp
    );
}
template Warrior* FileDealer::loadHero<Warrior>(std::istringstream& input);

void FileDealer::loadItem
(
    Inventory& inventory, std::istringstream& input, char itemClass
)
{
    switch (itemClass)
    {
        case 'I' : inventory.addItem( loadItem(input) ); break;
        case 'W' : inventory.addItem( loadWeapon(input) ); break;
        case 'A' : inventory.addItem( loadArmor(input) ); break;
        case 'S' : inventory.addItem( loadShield(input) ); break;
    }
}

Item FileDealer::loadItem(std::istringstream& input)
{
    int price;
    float weight;
    std::string name;

    input >> name >> price >> weight;

    Utils::ununderscoreSpaces(name);

    return Item(name, price, weight);
}

Weapon FileDealer::loadWeapon(std::istringstream& input)
{
    unsigned short minCriticalDice, criticalMultiplier;
    short diceQuantity, diceNumber, damageType, weaponType;
    int price;
    float weight;
    std::string name;

    input >> name >> price >> weight >> diceQuantity >> diceNumber
        >> minCriticalDice >> criticalMultiplier >> damageType >> weaponType;

    Utils::ununderscoreSpaces(name);

    return Weapon
    (
        name, price, weight, diceQuantity, static_cast<Dice>(diceNumber),
        minCriticalDice, criticalMultiplier,
        static_cast<DamageType>(damageType), static_cast<WeaponType>(weaponType)
    );
}

Armor FileDealer::loadArmor(std::istringstream& input)
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

Shield FileDealer::loadShield(std::istringstream& input)
{
    unsigned short minCriticalDice, criticalMultiplier;
    // Creating dummy variable to read the unecessary WeaponType, shield's
    // weapon type are aways one-handed (rule in the constructor).
    short diceQuantity, diceNumber, damageType, dummy;
    int price, armorClassBonus, armorPenalty;
    float weight;
    std::string name;

    input >> name >> price >> weight >> diceQuantity >> diceNumber
        >> minCriticalDice >> criticalMultiplier >> damageType >> dummy
        >> armorClassBonus >> armorPenalty;

    Utils::ununderscoreSpaces(name);

    return Shield
    (
        name, price, weight, diceQuantity, static_cast<Dice>(diceNumber),
        minCriticalDice, criticalMultiplier,
        static_cast<DamageType>(damageType), armorClassBonus, armorPenalty
    );
}

void FileDealer::loadEquippedItems
(
    std::unique_ptr<Hero>& t_hero, std::istringstream& input
)
{
    char itemClass = '0';

    // Loading the equipped items saved with the hero.
    while(input >> itemClass)
    {
        switch (itemClass)
        {
            case 'W': t_hero->set_equippedWeapon
            (
                FileDealer::loadWeapon(input)
            );
            break;
            case 'S': t_hero->set_equippedShield
            (
                FileDealer::loadShield(input)
            );
            break;
            case 'A': t_hero->set_equippedArmor
            (
                FileDealer::loadArmor(input)
            );
            break;  
        } // switch
    }
}

void FileDealer::loadInventory
(
    Party& t_party, std::array<std::unique_ptr<Hero>, 4>& t_heroes
)
{
    char itemClass;
    std::string itemString;
    std::ifstream inventoryFile;

    Inventory& inventory = t_party.get_inventory();

    inventoryFile.open("./data/inventory.dat", std::ios::in);

    inventory.reset();

    for (size_t i = 0; i < 4; ++i)
    {
        if(t_heroes[i])
        {
            inventory.set_capacity
            (
                inventory.get_capacity() + (t_heroes[i]->get_strength() * 10.f)
            );
        }
        else break;
    }

    // Loading the inventory items line by line.
    while( std::getline(inventoryFile, itemString) )
    {
        std::istringstream input(itemString);

        input >> itemClass;

        FileDealer::loadItem(inventory, input, itemClass);
    }

    inventoryFile.close();
}

void FileDealer::saveHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes)
{
    std::ofstream heroesFile, inventoryFile;
    heroesFile.open("./data/heroes.dat", std::ios::out);

    for(size_t i = 0; i < 4; i++)
    {
        if(t_heroes[i]) heroesFile << t_heroes[i]->getIdAsString() << '\n';
        else break;
    }

    heroesFile.close();
}

void FileDealer::loadHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes)
{
    char heroClass;
    std::string hero;
    std::ifstream heroFile;

    heroFile.open("./data/heroes.dat", std::ios::in);

    for(size_t i = 0; i < 4; i++)
    {
        if( std::getline(heroFile, hero) )
        {
            if( hero.empty() ) continue;

            std::istringstream input(hero);

            input >> heroClass;

            switch (heroClass)
            {
                case 'G': t_heroes[i].reset
                (
                    FileDealer::loadHero<Warrior>(input)
                );
                break;
            } // switch
            
            if(t_heroes[i]) loadEquippedItems(t_heroes[i], input);
        } // if
        else break;
    }
    heroFile.close();
}

void FileDealer::loadGame(Party& t_party)
{
    std::array<std::unique_ptr<Hero>, 4>& heroes = t_party.get_heroes();

    loadHeroes(heroes);

    loadInventory(t_party, heroes);
}