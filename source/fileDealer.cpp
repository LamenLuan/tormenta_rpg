#include "../headers/fileDealer.hpp"

template<typename T> T* FileDealer::loadHero(std::istringstream& input)
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
template Warrior* FileDealer::loadHero<Warrior>(std::istringstream& input);

void FileDealer::loadItem
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
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::istringstream& input, uint8_t index
)
{
    char itemClass = '0';

    // Loading the equipped items saved with the hero.
    while(input >> itemClass)
    {
        switch (itemClass)
        {
            case 'W': t_heroes[index]->set_equippedWeapon
            (
                FileDealer::loadWeapon(input)
            );
            break;
            case 'S': t_heroes[index]->set_equippedShield
            (
                FileDealer::loadShield(input)
            );
            break;
            case 'A': t_heroes[index]->set_equippedArmor
            (
                FileDealer::loadArmor(input)
            );
            break;  
        } // switch
    }
}

void FileDealer::loadInventory
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes, uint8_t index
)
{
    char itemClass;
    std::string itemString;
    std::ifstream inventoryFile;

    inventoryFile.open
    (
        "./data/inventory" + std::to_string(index) + ".dat", std::ios::in
    );
    
    // Loading the inventory items line by line.
    while( std::getline(inventoryFile, itemString) )
    {
        std::istringstream input(itemString);

        input >> itemClass;

        FileDealer::loadItem
        (
            t_heroes[index]->get_backpack(), input, itemClass
        );
    }

    inventoryFile.close();
}

void FileDealer::saveHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes)
{
    std::ofstream heroesFile, inventoryFile;
    heroesFile.open("./data/heroes.dat", std::ios::out);

    for(size_t i = 0; i < 4; i++)
    {
        if(t_heroes[i]) 
        {
            heroesFile << t_heroes[i]->getIdAsString() << '\n';
            inventoryFile.open
            (
                "./data/inventory" + std::to_string(i) + ".dat", std::ios::out
            );
            
            for (auto &i : t_heroes[i]->get_backpack().get_items() )
            {
                inventoryFile << i->getIdAsString() << '\n';
            }

            inventoryFile.close();
        } // if
        else break;
    }

    heroesFile.close();
}

bool FileDealer::loadHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes)
{
    bool anyHero = false;
    char heroClass;
    std::string hero;
    std::ifstream heroFile;

    heroFile.open("./data/heroes.dat", std::ios::in);

    for(size_t i = 0; i < 4; i++)
    {
        if( std::getline(heroFile, hero) )
        {
            if( hero.empty() ) continue;
            anyHero = true;

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

            loadEquippedItems(t_heroes, input, i);

            loadInventory(t_heroes, i);

        } // if
        else if (anyHero) break;
        else return false;
    }

    heroFile.close();
    return true;
}