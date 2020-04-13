#include <vector>

#include "weapon.hpp"
#include "armor.hpp"
#include "shield.hpp"

#ifndef TORMENTA_INVENTORY_HPP
#define TORMENTA_INVENTORY_HPP

class Inventory
{
private:
    std::vector<Item*> m_items;
    float m_capacity{0};
    float m_currentWeight{0};

public:
    explicit Inventory(float t_limit);
    virtual ~Inventory();

    float get_capacity() const;
    float get_currentWeight() const;
    std::vector<Item*> get_items() const; 

    void set_capacity(float t_capacity);
    void set_currentWeight(float t_currentWeight);

    template <typename T> void addItem(const T& item);
    void removeItem(size_t index);
};

#endif // TORMENTA_INVENTORY_HPP