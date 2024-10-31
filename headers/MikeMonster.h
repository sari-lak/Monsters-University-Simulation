#ifndef MIKEMONSTER_H
#define MIKEMONSTER_H
#include <iostream>
#include "Monster.h"
#include "BookStack.h"

// Derived class for Mike
class MikeMonster : public Monster {
public:
    // Declare constructor for MikeMonster
    MikeMonster();

    // Declare particular abilities
    void jokes();
};
#endif // MIKEMONSTER_H