
/**
 * @file main.cpp
 * @brief This file contains the main function that executes the Monsters University simulation.
 */

#include <iostream>
#include "Monster.h"
#include "MikeMonster.h"
#include "SullyMonster.h"
#include "RandallMonster.h"
#include "Boo.h"
#include "Student.h"
#include "CourseStructure.h"
#include "MUGraduate.h"
#include "Book.h"
#include "BookStack.h"
using namespace std;


/**
 * @brief The main function of the program.
 * 
 * This function is the entry point of the program. It creates monsters, initializes the curriculum,
 * determines student admission, defines students, presents book stacks for each academic year,
 * allows students to study and pass their exams, and finally, graduates the students.
 * 
 * @return int The exit status of the program.
 */
int main(){

    // Create the monsters
    /* This code is creating instances of different character classes and calling a describe method 
    on each instance to print a description of the character. */
    MikeMonster mike;
    mike.describe();
    mike.jokes(); // Custom ability
    cout<< endl;

    SullyMonster sully;
    sully.describe();
    sully.growl(); // Custom ability
    cout<< endl;

    RandallMonster randall;
    randall.describe();
    randall.invisibility(); // Custom ability
    cout<< endl;

    Boo boo;
    boo.describe();
    boo.coo(); // Custom ability  
    cout<< endl;

    // Create the curriculum
    BookStack stack2(5);
    vector <Book> books;
    books.push_back(Book("SCARING: A Student's Complete Guide to Scaring Human Children ages 2-11 ", "Monsters University", "blue", "Scaring", 847));
    books.push_back(Book("Secrets of the Element of Surprise", "Monsters University", "Red", "Scaring", 675));
    books.push_back(Book("Scare Techniques and Psychology", "Monsters University", "Blue", "Scaring", 512));
    books.push_back(Book("Bees, Wolves, Beasts and more", "Monsters University", "Green", "Scaring", 432));
    books.push_back(Book("The Rustling Whisper", "Monsters University", "Yellow", "Scaring", 321));

    // Create a CourseStructure object with books
    CourseStructure course(books);
    int total_books = course.getTotalNumberofBooks();
    cout<< "The total number of books in the course is: "<<total_books<<endl;

    // Determine Student Admission
    boo.admit(course);
    cout<< endl;

    Student sully_student = sully.admit(course); // so now Sully is defined as a Student in year 0
    Student randall_student = randall.admit(course);
    Student mike_student = mike.admit(course); // so now Mike is defined as a Student in year 0
    cout<< endl;

    // Define the students, with more time this process through the years could have also been a function
    vector <Student> students = {sully_student, randall_student, mike_student};
    bool hard_working;
    for (int i = 0; i < students.size(); i++){
        students[i].SetYear();
        students[i].SetScare();

        if (students[i].getName() == "Sully")
            hard_working = false;
        else
            hard_working = true;
        
        students[i].SetType(course, hard_working);
        cout<<endl;
    }

    // Present the 1st year books stack
    // cout<<"This is the first year at Monsters University."<<endl;
    course.getAcademicYear(CourseStructure::FIRST_YEAR);
    vector<BookStack> first_year = course.getBookStacks(CourseStructure::FIRST_YEAR);
    first_year[0].getAllBooksinStack(); // Display first year books
    cout<< endl;

    // Studying the first year curriculum
    for (int i = 0; i < students.size(); i++){
        students[i].learn(first_year[0]);
        students[i].pass();
        cout<<endl;
    }

    // Present the 2nd year books stack
    // cout<<"This is the second year at Monsters University."<<endl;
    course.getAcademicYear(CourseStructure::SECOND_YEAR);
    vector<BookStack> second_year = course.getBookStacks(CourseStructure::SECOND_YEAR);
    second_year[0].getAllBooksinStack(); // Display second year books
    cout<< endl;
    
    // Studying the second year curriculum
    for (int i = 0; i < students.size(); i++){
        students[i].learn(second_year[0]);
        students[i].pass();
        cout<<endl;
    }

    // Present the 3rd year books stack
    // cout<<"This is the third year at Monsters University."<<endl;
    course.getAcademicYear(CourseStructure::THIRD_YEAR);
    vector<BookStack> third_year = course.getBookStacks(CourseStructure::THIRD_YEAR);
    third_year[0].getAllBooksinStack(); // Display third year books
    cout<< endl;
    
    // Studying the third year curriculum
    for (int i = 0; i < students.size(); i++){
        students[i].learn(third_year[0]);
        students[i].pass();
        cout<<endl;
    }

    // Graduation
    for (int i = 0; i < students.size(); i++){
        MUGraduate graduate(students[i]);
        graduate.graduate();
    }
    return 0;
}