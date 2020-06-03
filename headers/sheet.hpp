#include "armor.hpp"
#include "shield.hpp"

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

    std::unique_ptr<Weapon> m_naturalWeapon{nullptr};

public:
    Sheet(
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
        unsigned short t_currentLife = 0u
    );
    virtual ~Sheet();

    const std::string& get_name() const;
    // Returning u_shorts to suport Character::getIdAsString()
    unsigned short get_level() const;
    unsigned short get_strength() const;
    unsigned short get_dexterity() const;
    unsigned short get_constitution() const;
    unsigned short get_inteligence() const;
    unsigned short get_wisdom() const;
    unsigned short get_charisma() const;
    unsigned short get_maxLife() const;
    unsigned short get_currentLife() const;
    Weapon& get_naturalWeapon() const;

    void set_name(const std::string& t_name);
    void set_level(uint8_t t_level);
    void set_strength(uint8_t t_strength);
    void set_dexterity(uint8_t t_dexterity);
    void set_constitution(uint8_t t_constitution);
    void set_inteligence(uint8_t t_inteligence);
    void set_wisdom(uint8_t t_wisdom);
    void set_charisma(uint8_t t_charisma);
    void set_maxLife(unsigned short t_maxLife);
    void set_currentLife(unsigned short t_currentLife);
    void set_naturalWeapon(const Weapon& t_naturalWeapon);

    static short modifier(short t_atribute);
    virtual int initiativeBonus() const = 0;

    virtual std::string show() const = 0;

    friend std::ostream &operator<<
        (std::ostream &t_stream, const Sheet &t_sheet);
};

#endif //TORMENTA_SHEET_HPP