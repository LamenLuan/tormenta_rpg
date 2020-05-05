#include <memory>

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

    std::unique_ptr<Weapon> m_naturalWeapon{nullptr};

public:
    Sheet();
    Sheet(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife);
    virtual ~Sheet();

    const std::string& get_name() const;
    uint8_t get_level() const;
    uint8_t get_strength() const;
    uint8_t get_dexterity() const;
    uint8_t get_constitution() const;
    uint8_t get_inteligence() const;
    uint8_t get_wisdom() const;
    uint8_t get_charisma() const;
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

    virtual int strength() const;
    virtual int dexterity() const;
    virtual int constitution() const;
    virtual int inteligence() const;
    virtual int wisdom() const;
    virtual int charisma() const;

    static int modifier(int t_atribute);
    virtual int initiativeBonus() const = 0;

    virtual std::string show() const = 0;

    friend std::ostream &operator<<
        (std::ostream &t_stream, const Sheet &t_sheet);
};

#endif //TORMENTA_SHEET_HPP