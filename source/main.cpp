#include "../headers/game.hpp"

int main(int, char**) {
    Warrior hero("Perseu", 17, 14, 18, 16, 12, 16, 6, Race::HUMAN, 150);

    hero.get_inventory().addItem(
        Weapon("Spear", 5, 2.5f, 1u, Dice::D6, 20u, 3u, DamageType::PIERCE)
    );

    hero.set_equipedWeapon(*dynamic_cast<Weapon*>
    (
        hero.get_inventory().get_items().at(0)
    ));

    return 0;
}