#ifndef SULLYMONSTER_H
#define SULLYMONSTER_H
#include <iostream>
#include "Monster.h"

// Derived class for Sully
class SullyMonster : public Monster {
public:
    // Declare constructor for MikeMonster
    SullyMonster();

    // Declare particular abilities
    void growl();
};
#endif // SULLYMONSTER_H