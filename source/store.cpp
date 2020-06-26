#include "../headers/store.hpp"

Store::Store(float t_priceMultiplier, StoreType t_storeType)
    :
    m_priceMultiplier(t_priceMultiplier), m_storeType(t_storeType)
{
    switch (m_storeType)
    {
    case StoreType::ARMORER :
        /* code */
        break;
    
    default:
        break;
    }
}

Store::~Store() = default;