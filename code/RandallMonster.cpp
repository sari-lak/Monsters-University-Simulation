/**
 * @file RandallMonster.cpp
 * @brief Implementation file for the RandallMonster class.
 * 
 * This file contains the implementation of the RandallMonster class, which is a derived class of the Monster class.
 * It defines the constructor and two member functions: slither() and invisibility().
 */
#include <iostream>
#include "RandallMonster.h"
/**
 * @brief Constructor for the RandallMonster class.
 * 
 * Initializes a RandallMonster object with specific characteristics.
 * Inherits from the Monster class and sets the character to Randall,
 * color to purple, gender to male, skin to scaly, size to medium,
 * feature to invisibility, and various other attributes.
 */
RandallMonster::RandallMonster() : Monster(Monster::Characters::Randall, Monster::Colors::purple, Monster::Genders::male, 
                            Monster::Skins::scaly, Monster::Sizes::medium, Monster::Features::invisibility, 
                            2, 4, 2, true, true, false, true) {}

/**
 * @brief RandallMonster's ability to turn invisible.
 * 
 * Prints a message indicating that Randall has turned invisible.
 */
void RandallMonster::invisibility(){
    cout << "Randall turns invisible." << endl;
}
