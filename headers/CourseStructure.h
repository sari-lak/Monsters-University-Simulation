#ifndef COURSESTRUCTURE_H
#define COURSESTRUCTURE_H
#include <iostream>
#include "BookStack.h"
#include <vector>

class CourseStructure {
public:
    enum AcademicYear {
        FIRST_YEAR,
        SECOND_YEAR,
        THIRD_YEAR
    };

    // Declare the BookStack objects for each academic year
    vector<BookStack> bookStacks[3];

    // Constructor for CourseStructure
    CourseStructure(vector<Book>&);
    
    // Get BookStack objects for a specific academic year
    vector<BookStack> getBookStacks(AcademicYear);

    // Declare the other getter functions
    int getNumberofStacks();
    int getNumberofBooks(AcademicYear);
    int getTotalNumberofBooks();
    string getAcademicYear(AcademicYear);

};
#endif // COURSESTRUCTURE_H