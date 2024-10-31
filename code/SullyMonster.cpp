/**
 * @brief The SullyMonster class represents a specific type of Monster called Sully.
 *        It inherits from the Monster class and defines its own constructor and abilities.
 */
#include <iostream>
#include "SullyMonster.h"

/**
 * @brief Constructs a SullyMonster object.
 *
 * This constructor initializes a SullyMonster object with the specified characteristics.
 * The SullyMonster is a subclass of the Monster class and inherits its properties.
 *
 * @return A SullyMonster object.
 */
SullyMonster::SullyMonster() : Monster(Monster::Characters::Sully, Monster::Colors::blue, Monster::Genders::male, 
                        Monster::Skins::furry, Monster::Sizes::large, Monster::Features::horns, 
                        2, 2, 2, true, true, false, true) {}

/**
 * @brief The growl function prints a message indicating that Sully is growling.
 */
void SullyMonster::growl(){
    cout << "Sully growls!!" << endl;
}
