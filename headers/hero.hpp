#include "character.hpp"

#ifndef TORMENTA_HERO_HPP
#define TORMENTA_HERO_HPP

class Hero : public Character
{
private:
    unsigned int m_currentExp{0u};
    unsigned int m_nextLevelExp{1000u};
    uint8_t m_lifePerLevel{1u};
public:
    // To create brand-new heroes.
    Hero
    (
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_lifePerLevel,
        Race t_race
    );
    // To load heroes.
    Hero
    (
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_lifePerLevel, Race t_race,
        unsigned short t_maxLife, unsigned short t_currentLife,
        unsigned int t_currentExp
    );
    virtual ~Hero();

    unsigned int get_currentExp() const;
    unsigned int get_nextLevelExp() const;
    int get_lifePerLevel() const;

    void set_currentExp(unsigned int t_currentExp);
    void set_nextLevelExp(unsigned int t_nextLevelExp);
    void set_lifePerLevel(uint8_t t_lifePerLevel);

    void addExp(int t_exp);
    
    std::string showStats() const;
    std::string show() const;
    virtual std::string getIdAsString() const = 0;
};

#endif // TORMENTA_HERO_HPP