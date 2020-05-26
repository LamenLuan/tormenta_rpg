#include "./exception-types/fullInventory.hpp"
#include "../source/hero-classes/warrior.hpp"

#ifndef TORMENTA_INVENTORY_HPP
#define TORMENTA_INVENTORY_HPP

class Inventory
{
private:
    std::vector<Item*> m_items;
    float m_capacity{0.f};
    float m_currentWeight{0.f};

public:
    Inventory();
    virtual ~Inventory();

    std::vector<Item*> get_items() const;
    float get_capacity() const;
    float get_currentWeight() const;

    void set_capacity(float t_capacity);
    void set_currentWeight(float t_currentWeight);

    template<typename T> void addItem(const T& t_item);
    void removeItem(size_t index);

    void reset();
};

#endif // TORMENTA_INVENTORY_HPP