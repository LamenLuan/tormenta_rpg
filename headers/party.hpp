#include "inventory.hpp"

#ifndef TORMENTA_PARTY_HPP
#define TORMENTA_PARTY_HPP

class Party
{
private:
    unsigned int m_coins{0u};
    Inventory m_inventory;
    std::array<std::unique_ptr<Hero>, 4> m_heroes;
public:
    Party();
    virtual ~Party();

    void set_coins(unsigned int t_coins);

    unsigned int get_coins();
    Inventory& get_inventory();
    std::array<std::unique_ptr<Hero>, 4>& get_heroes();

    template<typename T> void addHero
    (
        T* t_hero, std::unique_ptr<Hero>& t_pointer
    );

    void equipWeapon(Hero& t_hero, size_t t_index);
    void equipArmor(Hero& t_hero, size_t t_index);
    void equipShield(Hero& t_hero, size_t t_index);

    void reset();
};

#endif