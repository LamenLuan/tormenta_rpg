#include "../headers/armor.hpp"

Armor::Armor
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, int8_t t_armorClassBonus,
    int8_t t_armorPenalty, int8_t t_maximumDexterity
)
    :
    Item(std::move(t_name), t_price, t_weight),
    MagicalItem(t_magicalLevel),
    DefenceItem(t_armorClassBonus, t_armorPenalty),
    m_maximumDexterity(t_maximumDexterity)
{
}

Armor::~Armor() = default;

short Armor::get_maximumDexterity() const
{
    return m_maximumDexterity;
}

void Armor::set_maximumDexterity(int8_t t_maximumDexterity)
{
    m_maximumDexterity = t_maximumDexterity;
}

std::string Armor::armorInfo() const
{
    std::stringstream stream;

    stream << defenceItemInfo() << '\n'
        << "Maximum dexteriry bonus: "
        << std::showpos << get_maximumDexterity();

    return stream.str();
}

std::string Armor::showArmor() const
{
    std::stringstream stream;

    stream << showName() << '\n' << armorInfo();

    return stream.str();
}

std::string Armor::show() const
{
    std::stringstream stream;
    
    stream << Item::show() << armorInfo() << '\n';
        
    return stream.str();
}

std::string Armor::getIdAsString() const
{
    std::stringstream stream;

    stream << "A " << defenceItemId() << " " <<  get_maximumDexterity();

    return stream.str();
}