#include "../headers/store.hpp"

Store::Store(float t_priceMultiplier, StoreType t_storeType)
    :
    m_priceMultiplier(t_priceMultiplier), m_storeType(t_storeType)
{
    Item* (* generator) (size_t) = nullptr;
    size_t quantity = 0;

    switch (m_storeType)
    {
        case StoreType::WEAPONSMITH :
        {
            generator = ItemGenerator::generateWeapon;
            quantity = ItemGenerator::weaponQuantity;
        } break;

        case StoreType::ARMORER :
        {
            generator = ItemGenerator::generateDefenceItem;
            quantity =
                ItemGenerator::armorQuantity + ItemGenerator::shieldQuantity;
        } break;

        case StoreType::GENERAL :
        {
            generator = ItemGenerator::generateItem;
            quantity = 
                ItemGenerator::weaponQuantity + ItemGenerator::armorQuantity +
                ItemGenerator::shieldQuantity;
        } break;
    }

    for (size_t i = 0; i < quantity; ++i)
    {
        m_items.push_back( generator(i) );
    }
}

Store::~Store()
{
    for (auto &i : m_items)
    {
        delete i;
    }
}

float Store::get_priceMultiplier() const
{
    return m_priceMultiplier;
}

StoreType Store::get_storeType() const
{
    return m_storeType;
}

std::vector<Item*>& Store::get_items()
{
    return m_items;
}

void Store::set_priceMultiplier(float t_priceMultiplier)
{
    m_priceMultiplier = t_priceMultiplier;
}

void Store::set_storeType(StoreType t_storeType)
{
    m_storeType = t_storeType;
}