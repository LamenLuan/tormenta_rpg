#include "backpack.hpp"

#ifndef TORMENTA_SHEET_HPP
#define TORMENTA_SHEET_HPP

// Basic data that characters and creatures will inherit.
class Sheet
{

protected:
    std::string m_name{""};

    uint8_t m_strength{10u};
    uint8_t m_dexterity{10u};
    uint8_t m_constitution{10u};
    uint8_t m_inteligence{10u};
    uint8_t m_wisdom{10u};
    uint8_t m_charisma{10u};

    uint8_t m_level{1u};

    unsigned short m_maxLife{0u};
    unsigned short m_currentLife{0u};

    Weapon m_naturalWeapon;

public:
    Sheet();
    Sheet(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife);
    virtual ~Sheet();

    const std::string &get_name() const;
    unsigned short get_level() const;
    unsigned short get_strength() const;
    unsigned short get_dexterity() const;
    unsigned short get_constitution() const;
    unsigned short get_inteligence() const;
    unsigned short get_wisdom() const;
    unsigned short get_charisma() const;
    unsigned short get_maxLife() const;
    unsigned short get_currentLife() const;
    short get_armorClass() const;
    Weapon& get_naturalWeapon();

    void set_name(std::string t_name);
    void set_level(short t_level);
    void set_strength(short t_strength);
    void set_dexterity(short t_dexterity);
    void set_constitution(short t_constitution);
    void set_inteligence(short t_inteligence);
    void set_wisdom(short t_wisdom);
    void set_charisma(short t_charisma);
    void set_maxLife(short t_maxLife);
    void set_currentLife(short t_currentLife);
    void set_armorClass(short t_armorClass);
    void set_naturalWeapon(Weapon& t_naturalWeapon);

    virtual short strength() const;
    virtual short dexterity() const;
    virtual short constitution() const;
    virtual short inteligence() const;
    virtual short wisdom() const;
    virtual short charisma() const;
    virtual short armorClass() const = 0;

    short modifier(uint8_t t_atribute) const;
    virtual short initiativeBonus() const = 0;

    const std::string showStats() const;
    virtual const std::string show() const = 0;

    friend std::ostream &operator<<
        (std::ostream &t_stream, const Sheet &t_sheet);
    std::string getIdAsString() const;
};

#endif //TORMENTA_SHEET_HPP