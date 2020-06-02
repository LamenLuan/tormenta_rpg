#include "../headers/equipableItem.hpp"

EquipableItem::EquipableItem
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicLevel
)
    :
    Item(std::move(t_name), t_price, t_weight),
    m_magicLevel(t_magicLevel)
{
}

EquipableItem::~EquipableItem() = default;

void EquipableItem::set_magicLevel(uint8_t t_magicLevel)
{
    m_magicLevel = t_magicLevel;
}

unsigned short EquipableItem::get_magicLevel() const
{
    return m_magicLevel;
}

std::string EquipableItem::showName() const
{
    std::stringstream stream;

    stream << get_name();

    if(m_magicLevel) stream << " " << std::showpos
        << static_cast<short>(m_magicLevel);
        
    return stream.str();
}

std::string EquipableItem::equipableItemId() const
{
    std::stringstream stream;

    stream << itemId() << " " << m_magicLevel;

    return stream.str();
}