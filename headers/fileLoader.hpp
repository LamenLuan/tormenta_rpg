#include "../source/hero-classes/warrior.hpp"

#ifndef TORMENTA_FILE_LOADER_HPP
#define TORMENTA_FILE_LOADER_HPP

class FileLoader
{
public:
    template<typename T> T* loadHero(std::istringstream& input);

    void loadItem
    (
        Backpack& backpack, std::istringstream& input, char itemClass
    );
    Item loadItem(std::istringstream& input);
    Weapon loadWeapon(std::istringstream& input);
    Armor loadArmor(std::istringstream& input);
    Shield loadShield(std::istringstream& input);
};

#endif // TORMENTA_FILE_LOADER_HPP