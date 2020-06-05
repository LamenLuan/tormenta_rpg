#include "../headers/magicalItem.hpp"

MagicalItem::MagicalItem
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel
)
    :
    Item(std::move(t_name), t_price, t_weight),
    m_magicalLevel(t_magicalLevel)
{
}

MagicalItem::~MagicalItem() = default;

void MagicalItem::set_magicalLevel(uint8_t t_magicalLevel)
{
    m_magicalLevel = t_magicalLevel;
}

unsigned short MagicalItem::get_magicalLevel() const
{
    return m_magicalLevel;
}

std::string MagicalItem::showName() const
{
    std::stringstream stream;

    stream << get_name();

    if(m_magicalLevel) stream << " " << std::showpos
        << static_cast<short>(m_magicalLevel);
        
    return stream.str();
}

std::string MagicalItem::equipableItemId() const
{
    std::stringstream stream;

    stream << itemId() << " " << m_magicalLevel;

    return stream.str();
}