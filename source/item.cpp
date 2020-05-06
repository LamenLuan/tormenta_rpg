#include "../headers/item.hpp"

#include <utility>

Item::Item()
{
    m_name = "";
}

Item::Item(std::string t_name, unsigned int t_price, float t_weight)
    :
    m_name( std::move(t_name) ), m_price(t_price), m_weight(t_weight)
{
    if (m_weight < 0.0f) m_weight = 0.1f;
}

Item::~Item() = default;

const std::string &Item::get_name() const { return m_name; }

unsigned int Item::get_price() const { return m_price; }

float Item::get_weight() const { return m_weight; }

void Item::set_name(std::string t_name) { m_name = std::move(t_name); }

void Item::set_price(unsigned int t_price) { m_price = t_price; }

void Item::set_weight(float t_weight)
{
    if (t_weight >= 0.0f) m_weight = t_weight;
}

std::string Item::show() const {
    std::stringstream stream;

    stream 
        << "Item: " << m_name << '\n'
        << "Price: " << m_price << " PO" << '\n'
        << "Weight: " << std::fixed << std::setprecision(2) << m_weight << "kg"
            << '\n';

    return stream.str();
}

std::string Item::itemId() const
{
    std::stringstream stream;
    std::string name(m_name);

    Utils::underscoreSpaces(name);

    stream << name << " " << m_price << " " << m_weight;
    
    return stream.str();
}

std::string Item::getIdAsString() const
{
    std::stringstream stream;

    stream << "I " << itemId();
    
    return stream.str();
}

std::ostream &operator<<(std::ostream &t_stream, const Item &t_item)
{
    t_stream << t_item.show();

    return t_stream;
}