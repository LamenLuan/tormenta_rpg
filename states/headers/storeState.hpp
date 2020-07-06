#include "playableState.hpp"
#include "../../headers/store.hpp"

#ifndef TORMENTA_STORE_STATE_HPP
#define TORMENTA_STORE_STATE_HPP

class StoreState : public PlayableState
{
private:
    Store& m_store;
public:
    StoreState
    (
        Party& t_party, std::stack< std::unique_ptr<State> >& t_states,
        Store& t_store
    );
    virtual ~StoreState();

    void update();

    std::string storeTypeName() const;
};

#endif