#include <vector>

#include "item.hpp"
#include "itemGenerator.hpp"
#include "./enum-types/storeType.hpp"

#ifndef TORMENTA_STORE_HPP
#define TORMENTA_STORE_HPP

class Store
{
private:
    float m_priceMultiplier{1.f};
    StoreType m_storeType{StoreType::GENERAL};
    std::vector<Item*> m_items{};
public:
    Store(float t_priceMultiplier, StoreType t_storeType);

    float get_priceMultiplier() const;
    StoreType get_storeType() const;
    std::vector<Item*>& get_items();

    void set_priceMultiplier(float t_priceMultiplier);
    void set_storeType(StoreType t_storeType);

    virtual ~Store();
};

#endif