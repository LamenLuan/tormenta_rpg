#include "./headers/inventoryState.hpp"

InventoryState::InventoryState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
    PlayableState(t_party, t_states)
{
}

InventoryState::~InventoryState()
{
}

void InventoryState::update()
{
    bool previous = false, next = false;
    int choice;
    const Inventory& inventory = get_party().get_inventory();
    const std::vector<Item*>& items =
        get_party().get_inventory().get_items();

    for (size_t i = 0; !get_quit();)
    {
        system("CLS");

        std::cout << "INVENTORY OVERALL" << "\n\n";

        std::cout << "Items: " << i + 1 << "/" << items.size() << '\n'
        << "Weight: " << inventory.get_currentWeight() << "/"
        << inventory.get_capacity() << "\n\n";

        std::cout << *items[i] << '\n';

        if(i > 0)
        {
            previous = true;
            std::cout << "(1) Previous" << '\n';
        }

        if( i + 1 < items.size() )
        {
            next = true;
            std::cout << "(2) Next" << '\n';
        }

        std::cout << "(0) Quit" << '\n';

        choice = getIntChoice();

        if(choice < 0) continue;
        switch (choice)
        {
            case 0: set_quit(true); break;
            
            case 1:
            {
                if(previous)
                {
                    --i;
                    previous = false;
                }
            } break;

            case 2:
            {
                if(next)
                {
                    ++i;
                    next = false;
                }
            } break;

            default: break;
        }
    }
}