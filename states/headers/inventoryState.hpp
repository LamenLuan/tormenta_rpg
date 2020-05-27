#include "playableState.hpp"

#ifndef TORMENTA_INVENTORY_STATE_HPP
#define TORMENTA_INVENTORY_STATE_HPP

class InventoryState: public PlayableState
{
private:
    
public:
    InventoryState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states
    );
    virtual ~InventoryState();

    void equipItem(size_t t_index);
    bool removeItem
    (
        Inventory& t_inventory, const std::vector<Item*>& t_items,
        size_t t_index
    );

    void update();
};

#endif