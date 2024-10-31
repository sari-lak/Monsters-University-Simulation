#ifndef MUGRADUATE_H
#define MUGRADUATE_H
#include "Student.h"
using namespace std;

// Use inheritance to define the MUGraduate class
// This class is entirely dependent on the Student class
class MUGraduate{

private:
    Student student;

public:
    // Declare the constructor
    MUGraduate(Student& student);

    // Declare the functions
    void graduate();
};

#endif 
