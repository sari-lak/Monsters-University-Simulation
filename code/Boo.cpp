/**
 * @brief The Boo class represents a specific type of Monster called Boo.
 *        It inherits from the Monster class and adds its own abilities.
 */
#include <iostream>
#include "Boo.h"
// Define constructor for Boo
Boo::Boo() : Monster(Monster::Characters::Boo, Monster::Colors::pink, Monster::Genders::female, 
                            Monster::Skins::hairless, Monster::Sizes::small, Monster::Features::none, 
                            2, 2, 2, false, false, false, false) {}
    
/**
 * @brief The coo function represents the ability of a Boo to coo.
 */
void Boo::coo(){
    cout << "Boo coos !" << endl;
}