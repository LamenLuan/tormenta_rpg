#include <iostream>
#include <random>

#include "./enum-types/dice.hpp"

#ifndef TORMENTA_DICE_ROLL_HPP
#define TORMENTA_DICE_ROLL_HPP

class DiceRoll {
private:
    std::mt19937 m_gen;

public:
    DiceRoll();
    virtual ~DiceRoll();

    unsigned short operator()(Dice t_max);
};

#endif // TORMENTA_DICEROLL_HPP
