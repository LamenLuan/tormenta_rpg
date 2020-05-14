#include "playableState.hpp"

#ifndef TORMENTA_CHARACTERCREATION_HPP
#define TORMENTA_CHARACTERCREATION_HPP

class CharacterCreationState : public PlayableState
{
private:
    int m_phaseCount{0};
public:
    CharacterCreationState
    (
        std::array<std::unique_ptr<Hero>, 4>& t_heroes,
        std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~CharacterCreationState();

    void characterCreationLogo();

    void classSelection
    (
        uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
        uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma,
        uint8_t& heroClass
    );
    void humanBonusSelection
    (
        uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
        uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma
    );
    void raceSelection
    (
        uint8_t& strength, uint8_t& dexterity, uint8_t& constitution,
        uint8_t& inteligence, uint8_t& wisdom, uint8_t& charisma, Race& race
    );
    void nameSelection(std::string& heroName);

    void update();
};

#endif