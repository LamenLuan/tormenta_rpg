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

    void classSelection(std::unique_ptr<Hero>& hero);
    void humanBonusSelection(std::unique_ptr<Hero>& hero);
    void raceSelection(std::unique_ptr<Hero>& hero);

    void update();
};

#endif