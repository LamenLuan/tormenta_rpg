#include "./headers/storeState.hpp"

StoreState::StoreState
(
    Party& t_party, std::stack< std::unique_ptr<State> >& t_states,
    Store& t_store
)
    :
    PlayableState(t_party, t_states),
    m_store(t_store)
{
}

StoreState::~StoreState() = default;

void StoreState::update()
{
    bool previous = false, next = false, canBuy = false;
    int choice = -1;
    std::string message = "";
    const std::vector<Item*>& items = m_store.get_items();
    Inventory& inventory = get_party().get_inventory();

    for (size_t i = 0; i < items.size();)
    {
        unsigned int actualPrice =
            items[i]->get_price() * m_store.get_priceMultiplier();

        system("CLS");

        std::cout << storeTypeName() << '\n';

        std::cout << "Party's inventory:" << '\n'
            << "Weight: " << inventory.get_currentWeight()
                << "/" << inventory.get_capacity() << " kg" << '\n'
            << "Coins: " << get_party().get_coins() << " PO\n\n";

        std::cout << *items[i]
            << "Actual price: " << actualPrice << " PO" << '\n';

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

        if(get_party().get_coins() >= actualPrice)
        {
            if
            (
                inventory.get_currentWeight() + items[i]->get_weight()
                    <= inventory.get_capacity()
            )
            {
                canBuy = true;
                std::cout << "(3) Buy" << '\n';
            }
            else message = "Your inventory is full...";
        }
        else message = "You cannot afford this...";

        std::cout << '\n' << message << '\n';
        message.clear();

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
                if(canBuy)
                {
                    get_party().set_coins
                    (
                        get_party().get_coins() - actualPrice
                    );
                    inventory.addItem(*items[i]);

                    message = "Item added to your inventory!";
                    
                    canBuy = false;
                }
            }
        
            default: break;
        }
    }
}

std::string StoreState::storeTypeName() const
{
    std::stringstream stream;

    stream << "WELCOME TO THE ";

    switch ( m_store.get_storeType() )
    {
        case StoreType::ARMORER : stream << "ARMORER"; break;
        case StoreType::WEAPONSMITH: stream << "WEAPONSMITH"; break;
        default: stream << "SHOP"; break;
    }

    stream << '\n';

    return stream.str();
}