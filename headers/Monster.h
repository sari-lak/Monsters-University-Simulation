#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "Book.h"
#include "CourseStructure.h"
using namespace std;
// #include "Student.h" // this generates a circular dependency between Student and Monster

// Forward declaration of the Student class, this should resolve the circular dependency. ChatGBT source in references.txt
class Student;

// Declaration of the Monster class
class Monster
{
protected: // Changed access to protected to allow inheritance

    // Declare the enumators
    enum class Characters{Mike, Sully, Boo, Randall};
    enum class Colors{red, blue, green, yellow, purple, orange, pink, black, white, brown, grey};
    enum class Genders{male, female, nonbinary};
    enum class Features{none, horns, wings, fluffy, invisibility};
    enum class Sizes{small, medium, large};
    enum class Skins{furry, scaly, feathery, hairless};

    // Declare attributes from enumerators
    Characters name;
    Genders gender;
    Colors color;
    Skins skin;
    Sizes size;
    Features feature;

    // Declare the other attributes
    int nbEyes;
    int nbLegs;
    int nbArms;
    bool hasTail;
    bool isScary;

    bool hasBook; // for read action
    bool isSitting; // for sit action, ultimately attribute was no longer used

public:
    // Declare the default constructor
    Monster();

    // Declare Constructor
    Monster(Characters _name, Colors _color, Genders _gender, Skins _skin, Sizes _size, Features _feature, 
            int _nbEyes, int _nbArms, int _nbLegs, 
            bool _hasTail, bool _isScary, bool _hasBook, bool _isSitting);

    // Declare CourseStructure as a friend class
    friend class CourseStructure;
        
    // Declare the getter functions
    string getName();
    string getColor();
    string getGender();
    string getSkin();
    string getSize();
    string getFeature();

    int getnbEyes();
    int getnbArms();
    int getnbLegs();

    bool getisScary();
    bool gethasTail();
    bool gethasBook(); // for read action
    bool getisSitting(); // for sit action

    // Utility function to convert enum values to strings
    string CharactersToString(Characters color);
    string ColorsToString(Colors color);
    string GendersToString(Genders gender);
    string SkinsToString(Skins skin);
    string SizesToString(Sizes size);
    string FeaturesToString(Features feature);

    // Declare the pronoun function
    string getPronoun(bool);

    //Declare functions to describe actions
    void sit();
    void read();
    void describe();

    //Declare admission function
    Student admit(CourseStructure);
};

#endif // MONSTER_H