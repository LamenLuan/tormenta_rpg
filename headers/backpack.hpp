#include <vector>

#include "weapon.hpp"
#include "armor.hpp"
#include "shield.hpp"
#include "./exception-types/fulllBackpack.hpp"
#include "./exception-types/nullObject.hpp"

#ifndef TORMENTA_BACKPACK_HPP
#define TORMENTA_BACKPACK_HPP

class Backpack
{
private:
    std::vector<Item*> m_items;
    float m_capacity{0};
    float m_currentWeight{0};

public:
    explicit Backpack(float t_capacity, int t_coins);
    virtual ~Backpack();

    std::vector<Item*> get_items() const;
    float get_capacity() const;
    float get_currentWeight() const;

    void set_capacity(float t_capacity);
    void set_currentWeight(float t_currentWeight);

    template<typename T> void addItem(const T& t_item);
    void removeItem(size_t index);
};

#endif // TORMENTA_BACKPACK_HPP