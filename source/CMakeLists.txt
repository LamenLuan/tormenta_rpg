add_executable(Tormenta 
diceRoll.cpp rollSet.cpp item.cpp weapon.cpp armor.cpp shield.cpp backpack.cpp 
sheet.cpp character.cpp creature.cpp hero.cpp ./hero-classes/warrior.cpp
utils.cpp fileDealer.cpp game.cpp main.cpp)

target_link_libraries(Tormenta PUBLIC TormentaStates)