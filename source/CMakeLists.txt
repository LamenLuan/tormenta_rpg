add_executable(Tormenta 
diceRoll.cpp rollSet.cpp item.cpp magicalItem.cpp defenceItem.cpp weapon.cpp 
armor.cpp shield.cpp inventory.cpp sheet.cpp character.cpp creature.cpp hero.cpp 
./hero-classes/warrior.cpp itemGenerator.cpp utils.cpp fileDealer.cpp 
party.cpp game.cpp main.cpp)

target_link_libraries(Tormenta PUBLIC TormentaStates)