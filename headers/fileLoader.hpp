#include "../source/hero-classes/warrior.hpp"
#include "utils.hpp"

#ifndef TORMENTA_FILE_LOADER_HPP
#define TORMENTA_FILE_LOADER_HPP

class FileLoader
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
};

#endif // TORMENTA_FILE_LOADER_HPP