#include "../headers/backpack.hpp"

Backpack::Backpack(float t_capacity) : m_capacity(10.f * t_capacity)
{
}

Backpack::~Backpack() = default;

std::vector<Item*> Backpack::get_items() const { return m_items; }
float Backpack::get_capacity() const { return m_capacity; }
float Backpack::get_currentWeight() const { return m_currentWeight; }

void Backpack::set_capacity(float t_capacity)
{
    if(t_capacity >= m_currentWeight) m_capacity = t_capacity;
}
void Backpack::set_currentWeight(float t_currentWeight)
{
    if(m_currentWeight >= 0) m_currentWeight = t_currentWeight; 
}

template<typename T> void Backpack::addItem(const T& t_item)
{
    float itemWeight = t_item.get_weight();

    if(m_currentWeight + itemWeight <= m_capacity)
    {
        m_items.push_back(new T(t_item));
        m_currentWeight += itemWeight;
    }
    else throw FullBackpack();
}
template void Backpack::addItem<Item>(const Item& item);
template void Backpack::addItem<Armor>(const Armor& item);
template void Backpack::addItem<Weapon>(const Weapon& item);
template void Backpack::addItem<Shield>(const Shield& item);

void Backpack::removeItem(size_t index)
{
    if(index <= (m_items.size() - 1) )
    {
        m_currentWeight -= m_items[index]->get_weight();
        delete m_items[index];
        m_items.erase(m_items.begin() + index);
    }
    else throw NullObject();
}