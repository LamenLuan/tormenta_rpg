#include "./headers/newGameState.hpp"

NewGameState::NewGameState
(
    std::array<std::unique_ptr<Hero>, 4>& t_heroes,
    std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_heroes, t_states)
{
}

NewGameState::~NewGameState() = default;

void NewGameState::update()
{
    for ( auto &&i : get_heroes() )
    {
        i.reset();
    }
    
    get_states().push
    (
        std::make_unique<CharacterCreationState>
        (
            CharacterCreationState( get_heroes(), get_states() )
        )
    );

    get_states().top()->update();

    if(get_heroes()[0])
    {
        get_states().pop();

        get_states().push
        (
            std::make_unique<GameState>
            (
                GameState( get_heroes(), get_states() )
            )
        );

        set_quit(true);
    }
    else
    {
        set_quit(true);
    }
    
}