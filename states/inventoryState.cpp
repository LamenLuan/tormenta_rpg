#include "./headers/inventoryState.hpp"

InventoryState::InventoryState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states
)
:
    PlayableState(t_party, t_states)
{
}

InventoryState::~InventoryState() = default;

void InventoryState::equipItem(size_t t_index)
{
    int choice = -1;
    bool quit = false;

    const std::vector<Item*>& items =
        get_party().get_inventory().get_items();
    const std::array<std::unique_ptr<Hero>, 4>& heroes = 
        get_party().get_heroes();

    while (!quit)
    {
        system("CLS");

        std::cout << "INVENTORY OVERALL" << "\n\n"
            << "Equipping the " << items[t_index]->showName()
            << " for:" << "\n\n";
        
        for (size_t i = 0; i < 4; ++i)
        {
            if(heroes[i])
            {
                std::cout << '(' << i + 1 << ") "
                    << heroes[i]->get_name() << '\n';
            }
        }
        std::cout << "(0) Cancel" << '\n';

        choice = getIntChoice();

        if(choice == 0) break;
        else if(choice < 0 || choice > 4) continue;

        // Just adapting choice to arrays
        --choice;

        if(heroes[choice])
        {
            if( dynamic_cast<Shield*>(items[t_index]) )
            {
                get_party().equipShield(*heroes[choice], t_index);
            }
            else if( dynamic_cast<Armor*>(items[t_index]) )
            {
                get_party().equipArmor(*heroes[choice], t_index);
            }
            else get_party().equipWeapon(*heroes[choice], t_index);
        }

        quit = true;
    }
}

bool InventoryState::removeItem
(
    Inventory& t_inventory, const std::vector<Item*>& t_items,
    size_t t_index
)
{
    bool quit = false;
    int choice = -1;

    while (!quit)
    {
        system("CLS");

        std::cout << "INVENTORY OVERALL" << "\n\n"
            << "Do you really want to throw away " 
            << t_items[t_index]->get_name() << " ?" << "\n\n"
            << "(1) Yes" << '\n'
            << "(0) No" << '\n';

        choice = getIntChoice();

        if(choice == 0) break;
        else if(choice == 1)
        {
            t_inventory.removeItem(t_index);
            quit = true;
        }
    }

    return quit;
}

void InventoryState::update()
{
    bool previous = false, next = false, equippable = false;
    int choice;

    Inventory& inventory = get_party().get_inventory();
    const std::vector<Item*>& items =
        get_party().get_inventory().get_items();

    for (size_t i = 0; !get_quit();)
    {
        system("CLS");

        std::cout << "INVENTORY OVERALL" << "\n\n";

        std::cout << "Weight: " << inventory.get_currentWeight() << "/"
                << inventory.get_capacity() << '\n'
                << "Coins: " << get_party().get_coins() << " POs" << '\n';

        if( items.empty() ) std::cout << "Inventory empty..." << "\n\n";
        else
        {
            std::cout << "Items: " << i + 1 << "/" << items.size() << "\n\n";

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

            if
            ( dynamic_cast<EquipableItem*>(items[i]) )
            {
                equippable = true;
                std::cout << "(3) Equip" << '\n';
            }

            std::cout << "(4) Throw away" << '\n';
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

            case 3:
            {
                if(equippable)
                {
                    equipItem(i);
                    equippable = false;
                    return;
                }
            } break;

            case 4:
            {
                if( removeItem(inventory, items, i) ) return;
            } break;

            default: break;
        }
    }
}