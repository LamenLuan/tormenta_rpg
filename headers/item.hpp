#include <iostream>
#include <iomanip>

#include "utils.hpp"

#ifndef TORMENTA_ITEM_HPP
#define TORMENTA_ITEM_HPP

class Item
{

protected:
    std::string m_name;
    unsigned int m_price{0u};
    float m_weight{0.0f};

public:
    Item();
    Item(std::string t_name, unsigned int t_price, float t_weight);
    virtual ~Item();

    const std::string &get_name() const;
    unsigned int get_price() const;
    float get_weight() const;

    void set_name(std::string t_name);
    void set_price(unsigned int t_price);
    void set_weight(float t_weight);

    virtual const std::string show() const;
    std::string itemId() const;
    virtual std::string getIdAsString() const;
    friend std::ostream &operator<<(std::ostream &t_stream, const Item &t_item);
};

#endif // TORMENTA_ITEM_HPP