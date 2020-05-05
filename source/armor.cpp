#include "../headers/armor.hpp"

Armor::Armor() : Item() {}

Armor::Armor(std::string t_name, unsigned int t_price, float t_weight,
    int8_t t_armorClassBonus, int8_t t_armorPenalty, int8_t t_maximumDexterity)
    :
    Item(t_name, t_price, t_weight),
    m_armorClassBonus(t_armorClassBonus), m_armorPenalty(t_armorPenalty),
    m_maximumDexterity(t_maximumDexterity)
{
}

Armor::~Armor()
{
}

short Armor::get_armorClassBonus() const
{
    return m_armorClassBonus;
}

short Armor::get_maximumDexterity() const
{
    return m_maximumDexterity;
}

short Armor::get_armorPenalty() const
{
    return m_armorPenalty;
}

void Armor::set_armorClassBonus(int8_t t_armorClassBonus)
{
    m_armorClassBonus = t_armorClassBonus;
}

void Armor::set_maximumDexterity(int8_t t_maximumDexterity)
{
    m_maximumDexterity = t_maximumDexterity;
}

void Armor::set_armorPenalty(int8_t t_armorPenalty)
{
    m_armorPenalty = t_armorPenalty;
}

const std::string Armor::armorInfo() const
{
    std::stringstream stream;

    stream << std::showpos 
        << "Armor class bonus: " << get_armorClassBonus() << '\n'
        << "Maximum dexteriry: " << get_maximumDexterity() << '\n'
        << "Armor penalty: " << get_armorPenalty();

    return stream.str();
}

const std::string Armor::showArmor() const
{
    std::stringstream stream;

    stream << m_name << '\n' << armorInfo();

    return stream.str();
}

const std::string Armor::show() const
{
    std::stringstream stream;
    
    stream << Item::show() << armorInfo() << '\n';
        
    return stream.str();
}

std::string Armor::armorId() const
{
    std::stringstream stream;

    stream << get_armorClassBonus() << " " << get_armorPenalty() << " "
        << get_maximumDexterity();

    return stream.str();
}

std::string Armor::getIdAsString() const
{
    std::stringstream stream;

    stream << "A " << itemId() << " " <<  armorId();

    return stream.str();
}