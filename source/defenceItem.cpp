#include "../headers/defenceItem.hpp"

DefenceItem::DefenceItem(int8_t t_armorClassBonus, int8_t t_armorPenalty)
    :
    MagicalItem(),
    m_armorClassBonus(t_armorClassBonus), m_armorPenalty(t_armorPenalty)
{

}

DefenceItem::DefenceItem
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, uint8_t t_armorClassBonus, uint8_t t_armorPenalty
)
    :
    MagicalItem(std::move(t_name), t_price, t_weight, t_magicalLevel),
    m_armorClassBonus(t_armorClassBonus), m_armorPenalty(t_armorPenalty)
{
}

DefenceItem::~DefenceItem() = default;

unsigned short DefenceItem::get_armorClassBonus() const
{
    return m_armorClassBonus;
}

unsigned short DefenceItem::get_armorPenalty() const
{
    return m_armorPenalty;
}

void DefenceItem::set_armorClassBonus(uint8_t t_armorClassBonus)
{
    m_armorClassBonus = t_armorClassBonus;
}

void DefenceItem::set_armorPenalty(uint8_t t_armorPenalty)
{
    m_armorPenalty = t_armorPenalty;
}

short DefenceItem::totalArmorClassBonus() const
{
    return get_armorClassBonus() + get_magicalLevel();
}

std::string DefenceItem::defenceItemInfo() const
{
    std::stringstream stream;

    stream 
        << "Armor class bonus: +" << get_armorClassBonus();

    if( get_magicalLevel() ) stream << " (+" << get_magicalLevel() << ')';

    stream
        << '\n' << "Armor penalty: -" << get_armorPenalty();

    return stream.str();
}

std::string DefenceItem::defenceItemId() const
{
    std::stringstream stream;

    stream << magicalItemId() << " " << get_armorClassBonus()
        << " " << get_armorPenalty();

    return stream.str();
}