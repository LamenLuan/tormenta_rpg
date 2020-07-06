#include "./headers/newGameState.hpp"

NewGameState::NewGameState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
PlayableState(t_party, t_states)
{
}

NewGameState::~NewGameState() = default;

void NewGameState::update()
{
    Store store(1.f, StoreType::GENERAL);
    std::array<std::unique_ptr<Hero>, 4>& heroes = get_party().get_heroes();

    get_party().reset();
    
    get_states().push
    (
        std::make_unique<CharacterCreationState>
        (
            CharacterCreationState( get_party(), get_states())
        )
    );

    get_states().top()->update();

    if(heroes[0])
    {
        get_states().pop();

        // Initial gold for the party.
        get_party().set_coins(100u);

        get_states().push
        (
            std::make_unique<StoreState>
            (
                StoreState( get_party(), get_states(), store)
            )
        );

        get_states().top()->update();

        get_states().pop();

        get_states().push
        (
            std::make_unique<GameState>
            (
                GameState( get_party(), get_states() )
            )
        );
        
        set_quit(true);
    }
    else
    {
        set_quit(true);
    }
    
}