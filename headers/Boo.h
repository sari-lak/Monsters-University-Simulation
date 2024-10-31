#ifndef BOO_H
#define BOO_H
#include <iostream>
#include "Monster.h"

// Derived class for Boo
class Boo : public Monster {
public:
    // Define constructor for Boo
    Boo();

    // Declare particular abilities
    void coo();
};
#endif // BOO_H