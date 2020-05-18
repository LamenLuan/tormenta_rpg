#include "newGameState.hpp"

#ifndef TORMENTA_MAINMENUSTATE_HPP
#define TORMENTA_MAINMENUSTATE_HPP

class MainMenuState : public PlayableState
{
private:
    
public:
    MainMenuState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~MainMenuState();
    
    void update();
};

#endif