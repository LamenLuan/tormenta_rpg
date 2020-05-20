#include "playableState.hpp"

#ifndef TORMENTA_CHARACTER_CREATION_STATE_HPP
#define TORMENTA_CHARACTER_CREATION_STATE_HPP

class CharacterCreationState : public PlayableState
{
private:
    int m_phaseCount{0};
public:
    CharacterCreationState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~CharacterCreationState();

    void printCancelOption();
    
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