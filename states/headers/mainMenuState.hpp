#include "newGameState.hpp"

#ifndef TORMENTA_MAIN_MENU_STATE_HPP
#define TORMENTA_MAIN_MENU_STATE_HPP

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