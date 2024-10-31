/**
 * @file MUGraduate.cpp
 * @brief Implementation file for the MUGraduate class.
 * 
 * This file contains the implementation of the MUGraduate class, which represents a graduate of MU University.
 * The class is responsible for determining whether a student is eligible to graduate from MU University.
 */
#include <iostream>
#include "MUGraduate.h"
using namespace std;

/**
 * @brief Constructs a new MUGraduate object.
 * 
 * This constructor initializes a new MUGraduate object with the provided Student object.
 * 
 * @param student The Student object associated with the MUGraduate.
 */
MUGraduate::MUGraduate(Student& student) : student(student) {};

/**
 * Graduates the student from MU University.
 * If the student has passed all years, they are considered a Scarer.
 * Otherwise, they cannot graduate and are suggested to work in the Mail Room.
 */
void MUGraduate::graduate() {
    if (student.getYearPasses() == vector<bool> {true, true,true})
        cout << "Congratulations, " << student.getName() << ", you are now a Scarer!" << endl;
    else
        cout << "Sorry, " << student.getName() << ", you cannot graduate from MU University. Don't worry, they're always hiring in the Mail Room. " << endl;
}