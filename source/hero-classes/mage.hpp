#include "../../headers/hero.hpp"

#ifndef TORMENTA_MAGE_HPP
#define TORMENTA_MAGE_HPP

class Mage : public Hero
{
private:
    
public:
    Mage();
    Mage(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    Race t_race, int t_coins);
    
    virtual ~Mage();
};

#endif