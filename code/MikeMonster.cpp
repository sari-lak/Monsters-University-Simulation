/**
 * @file MikeMonster.cpp
 * @brief Implementation file for the MikeMonster class.
 */
#include <iostream>
#include "MikeMonster.h"

/**
 * @brief Constructor for MikeMonster class.
 * 
 * Initializes a MikeMonster object with specific characteristics.
 * 
 * @details The constructor sets the character to Mike, color to green, gender to male,
 * skin to scaly, size to small, feature to horns, and other attributes accordingly.
 * 
 * @param None
 * @return None
 */
MikeMonster::MikeMonster() : Monster(Monster::Characters::Mike, Monster::Colors::green, Monster::Genders::male, 
                            Monster::Skins::scaly, Monster::Sizes::small, Monster::Features::horns, 
                            1, 2, 2, false, false, false, true) {}
#
/**
 * Prints a joke related to the MikeMonster class.
 * The joke is: "Why did the monster eat a light bulb? Because he wanted a light snack!"
 */
void MikeMonster::jokes() {
    std::cout << "Mike makes a joke: Why did the monster eat a light bulb? Because he wanted a light snack!" << std::endl;
}

