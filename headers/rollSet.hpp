#include <iostream>
#include <vector>

#include "diceRoll.hpp"

#ifndef TORMENTA_ROLLSET_HPP
#define TORMENTA_ROLLSET_HPP

class RollSet
{
    
private:
    static DiceRoll m_random;
    uint8_t m_quantity{1u};
    Dice m_dice{Dice::D6};

public:
    RollSet();
    RollSet(uint8_t t_quantity, Dice t_dice);
    virtual ~RollSet();

    short get_quantity() const;
    Dice get_dice() const;

    void set_quantity(uint8_t t_quantity);
    void set_dice(Dice t_dice);

    std::vector<unsigned short> roll();
    std::string show() const;
};

#endif // TORMENTA_ROLLSET_HPP