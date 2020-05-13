#include <fstream>

#include "../source/hero-classes/warrior.hpp"

#ifndef TORMENTA_FILEDEALER_HPP
#define TORMENTA_FILEDEALER_HPP

class FileDealer
{
public:

    template<typename T> static T* loadHero(std::istringstream& input);

    static void loadItem
    (
        Backpack& backpack, std::istringstream& input, char itemClass
    );
    static Item loadItem(std::istringstream& input);
    static Weapon loadWeapon(std::istringstream& input);
    static Armor loadArmor(std::istringstream& input);
    static Shield loadShield(std::istringstream& input);

    void loadEquippedItems
    (
        std::array<std::unique_ptr<Hero>, 4>& t_heroes,
        std::istringstream& input, uint8_t index
    );
    void loadInventory
    (
        std::array<std::unique_ptr<Hero>, 4>& t_heroes, uint8_t index
    );

    void saveHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes);
    bool loadHeroes(std::array<std::unique_ptr<Hero>, 4>& t_heroes);
};

#endif // TORMENTA_FILEDEALER_HPP