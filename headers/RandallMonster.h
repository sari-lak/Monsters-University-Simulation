#ifndef RANDALLMONSTER_H
#define RANDALLMONSTER_H
#include <iostream>
#include "Monster.h"

// Derived class for Randall
class RandallMonster : public Monster {
public:
    // Define constructor for RandallMonster
    RandallMonster();
    
    // Declare particular abilities
    void invisibility();
};
#endif // RANDALLMONSTER_H