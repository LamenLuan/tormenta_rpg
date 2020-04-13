#include "character.hpp"

#ifndef TORMENTA_HERO_HPP
#define TORMENTA_HERO_HPP

class Hero : public Character
{
private:
    unsigned int m_currentExp{0u};
    unsigned int m_nextLevelExp{1000u};
public:
    
    void util_manageExp(uint8_t t_level);
    Hero(uint8_t t_level = 1);
    Hero(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
        Race t_race, int t_coins);
    virtual ~Hero();

    unsigned int get_currentExp() const;

    void addExp(int t_exp);
};

#endif // TORMENTA_HERO_HPP