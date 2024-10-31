#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Monster.h"
#include "Book.h"
#include "BookStack.h"
#include "CourseStructure.h"
using namespace std;

// Student class inherits attributes from Monster class, however incoporates many new attributes and methods
class Student : public Monster {
private:

    int ac_year; // academic year
    string type;
    vector <bool> year_passes; // vector to track which academic years the student passed
    vector <bool> books_read; // vector to track which books the student read
    // Abilities
    float scare;

public:
    // Default constructor
    Student();

    // Constructor
    Student(Characters _name, Colors _color, Genders _gender, Skins _skin, Sizes _size, Features _feature, 
            int _nbEyes, int _nbArms, int _nbLegs,
            bool _hasTail, bool _isScary, bool _hasBook, bool _isSitting, 
            int _ac_year, string _type, vector<bool> year_passes, vector <bool> books_read, int _scare);

    // Getter functions
    int getYear();
    string getType();
    int getScare();
    vector <bool> getYearPasses();

    // Setter functions
    void SetType(CourseStructure course, bool hard_working);
    void SetYear();
    void SetScare(Book _book = Book());

    // Action functions
    void learn(BookStack _bookstack = BookStack());
    bool pass();
};

#endif