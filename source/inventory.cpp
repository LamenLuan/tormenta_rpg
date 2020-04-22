#include "../headers/inventory.hpp"

Inventory::Inventory(float t_capacity) : m_capacity(10.f * t_capacity)
{
}

Inventory::~Inventory()
{
}

std::vector<Item*> Inventory::get_items() const { return m_items; }
float Inventory::get_capacity() const { return m_capacity; }
float Inventory::get_currentWeight() const { return m_currentWeight; }

void Inventory::set_capacity(float t_capacity)
{
    if(t_capacity >= m_currentWeight) m_capacity = t_capacity;
}
void Inventory::set_currentWeight(float t_currentWeight)
{
    m_currentWeight = t_currentWeight; 
}

template<typename T> void Inventory::addItem(const T& t_item)
{
    float itemWeight = t_item.get_weight();

    if(m_currentWeight + itemWeight <= m_capacity)
    {
        m_items.push_back(new T(t_item));
        m_currentWeight += itemWeight;
    }
    else throw new FullInventory;
}
template void Inventory::addItem<Item>(const Item& item);
template void Inventory::addItem<Armor>(const Armor& item);
template void Inventory::addItem<Weapon>(const Weapon& item);
template void Inventory::addItem<Shield>(const Shield& item);

void Inventory::removeItem(size_t index)
{
    if(index <= (m_items.size() - 1) )
    {
        m_currentWeight -= m_items[index]->get_weight();
        delete m_items[index];
        m_items.erase(m_items.begin() + index);
    }
    else throw new NullObject;
}