#include "../headers/armor.hpp"

Armor::Armor
(
    std::string t_name, unsigned int t_price, float t_weight,
    int8_t t_armorClassBonus, int8_t t_armorPenalty,
    int8_t t_maximumDexterity, ArmorType t_armorType
)
    :
    Item(std::move(t_name), t_price, t_weight),
    DefenceItem(t_armorClassBonus, t_armorPenalty),
    m_maximumDexterity(t_maximumDexterity), m_armorType(t_armorType)
{
}

Armor::Armor
(
    std::string t_name, unsigned int t_price, float t_weight,
    uint8_t t_magicalLevel, int8_t t_armorClassBonus,
    int8_t t_armorPenalty, int8_t t_maximumDexterity, ArmorType t_armorType
)
    :
    Item(std::move(t_name), t_price, t_weight),
    MagicalItem(t_magicalLevel),
    DefenceItem(t_armorClassBonus, t_armorPenalty),
    m_maximumDexterity(t_maximumDexterity), m_armorType(t_armorType)
{
}

Armor::~Armor() = default;

short Armor::get_maximumDexterity() const
{
    return m_maximumDexterity;
}

ArmorType Armor::get_armorType() const
{
    return m_armorType;
}

void Armor::set_maximumDexterity(int8_t t_maximumDexterity)
{
    m_maximumDexterity = t_maximumDexterity;
}

void Armor::set_armorType(ArmorType t_armorType)
{
    m_armorType = t_armorType;
}

std::string Armor::showArmorType() const
{
    switch (m_armorType)
    {
        case ArmorType::LIGHT : return "Light"; break;
        case ArmorType::MEDIUM : return "Medium"; break;
        default: return "Heavy"; break;
    }
}

std::string Armor::armorInfo() const
{
    std::stringstream stream;

    stream << defenceItemInfo() << '\n'
        << "Maximum dexteriry bonus: "
        << std::showpos << get_maximumDexterity() << '\n'
        << "Armor type: " << showArmorType();

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

    stream << "A " << defenceItemId() << " " <<  get_maximumDexterity()
        << " " << static_cast<int>(m_armorType);

    return stream.str();
}