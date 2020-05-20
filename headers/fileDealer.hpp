#include <fstream>

#include "./party.hpp"

#ifndef TORMENTA_FILE_DEALER_HPP
#define TORMENTA_FILE_DEALER_HPP

class FileDealer
{
public:

    template<typename T> static T* loadHero(std::istringstream& input);

    static void loadItem
    (
        Inventory& inventory, std::istringstream& input, char itemClass
    );
    static Item loadItem(std::istringstream& input);
    static Weapon loadWeapon(std::istringstream& input);
    static Armor loadArmor(std::istringstream& input);
    static Shield loadShield(std::istringstream& input);

    static void loadEquippedItems
    (
        std::unique_ptr<Hero>& t_hero, std::istringstream& input
    );
    static void loadInventory(Inventory& t_inventory);

    static void saveHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes);
    static void loadHeroes(Party& t_party);

    static void loadGame(Party& t_party);
};

#endif // TORMENTA_FILEDEALER_HPP