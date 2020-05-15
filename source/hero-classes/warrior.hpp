#include "../../headers/hero.hpp"

#ifndef TORMENTA_WARRIOR_HPP
#define TORMENTA_WARRIOR_HPP

class Warrior : public Hero
{
private:
    
public:
    Warrior
    (
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, Race t_race
    );
    Warrior
    (
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, Race t_race, unsigned short t_maxLife,
        unsigned short t_currentLife, unsigned int t_currentExp
    );
    
    virtual ~Warrior();

    std::string show() const;
    std::string getIdAsString() const;
};

#endif