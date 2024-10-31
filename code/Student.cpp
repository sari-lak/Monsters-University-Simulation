/**
 * @file Student.cpp
 * @brief Implementation file for the Student class.
 * 
 * This file contains the implementation of the Student class, which represents a student at Monsters University.
 * The Student class is derived from the Monster class and includes additional member variables and functions specific to a student.
 * The class provides functionality to set the type of the student, set the academic year, set the scare ability, learn from books, and check if the student has passed the current academic year.
 * 
 * @author [Your Name]
 */

#ifndef STUDENT_H
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Student.h"
#include "Monster.h" // base class
#include "CourseStructure.h" // composition just to get the total nb of books
using namespace std;

/**
 * @brief Default constructor for the Student class.
 */
Student::Student() : Monster(){};

/**
 * @brief Constructor for the Student class.
 * 
 * @param _name The name of the student.
 * @param _color The color of the student.
 * @param _gender The gender of the student.
 * @param _skin The skin type of the student.
 * @param _size The size of the student.
 * @param _feature The feature of the student.
 * @param _nbEyes The number of eyes of the student.
 * @param _nbArms The number of arms of the student.
 * @param _nbLegs The number of legs of the student.
 * @param _hasTail Whether the student has a tail or not.
 * @param _isScary Whether the student is scary or not.
 * @param _hasBook Whether the student has a book or not.
 * @param _isSitting Whether the student is sitting or not.
 * @param _ac_year The academic year of the student.
 * @param _type The type of the student.
 * @param year_passes The vector representing whether the student has passed each year.
 * @param _books_read The vector representing whether the student has read each book.
 * @param _scare The scare level of the student.
 */
Student::Student(Characters _name, Colors _color, Genders _gender, Skins _skin, Sizes _size, Features _feature, 
                        int _nbEyes, int _nbArms, int _nbLegs, 
                        bool _hasTail, bool _isScary, bool _hasBook, bool _isSitting, 
                        int _ac_year, string _type, vector<bool> year_passes, vector <bool> _books_read, int _scare)
                :Monster(_name, _color, _gender, _skin, _size, _feature, _nbEyes, _nbArms, _nbLegs, _hasTail, _isScary, _hasBook, _isSitting), 
                        ac_year(_ac_year), type(_type), year_passes(3, false), books_read(_books_read), scare(_scare){};

// Define the getter functions

/**
 * Retrieves the academic year of the student.
 *
 * @return The academic year of the student.
 */

int Student::getYear(){return ac_year;};
/**
 * @brief Get the type of the student.
 * 
 * @return std::string The type of the student.
 */

string Student::getType(){return type;};
/**
 * @brief Get the scare value of the student.
 * 
 * @return int The scare value of the student.
 */

int Student::getScare(){return scare;};
/**
 * Retrieves the year passes of the student.
 *
 * @return A vector of booleans representing the year passes of the student.
 */
vector <bool> Student::getYearPasses(){return year_passes;};

// Define the setter function for the student type
// ChatGBT helped ensure that the books_read vector is properly set and the random distribution code
// https://chat.openai.com/share/f79959df-e8f2-4d77-bd0a-2c16c582b1fb
/**
 * @brief Sets the type of the student based on their characteristics and course structure.
 * 
 * The function takes in the course structure and a boolean value indicating whether the student is hard working.
 * Based on the student's characteristics and work ethic, the function determines their type and assigns it to the 'type' member variable.
 * Additionally, the function populates the 'books_read' vector based on the student's type and the total number of books in the course.
 * 
 * @param course The course structure object containing information about the course.
 * @param hard_working A boolean value indicating whether the student is hard working.
 */
void Student::SetType(CourseStructure course, bool hard_working) {
        
    // If the student is scary and hard working then he is an Average student
    if (isScary && hard_working) {
        type = "Average";
        cout << getName() << " is a natural Scarer, but he's hardworking, so he'll be an average student (will read some of the books)." << endl;

        // Average students read some of the books
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1);
        books_read.resize(course.getTotalNumberofBooks()); // Resize the vector to the total number of books

        // Randomly assign books to be read
        for (int i = 0; i < books_read.size(); i++) {
            books_read[i] = dis(gen);
        }
        // cout<< books_read[0] << " "<< books_read[1] <<endl;
    }

    // If the student is scary and not hard working then he is a Slacker
    else if (isScary && !hard_working) {
        type = "Slacker";
        cout << getName() << " is a natural Scarer, but lazy, so he'll be a slacker (will read none of the books)." << endl;
        books_read.assign(course.getTotalNumberofBooks(), false); // Resize the vector and fill with false values
        // cout<< books_read[0] << " "<< books_read[1] <<endl;
    }

    // If the student is not scary and hard working then he is Diligent
    else if (!isScary && hard_working) {
        type = "Diligent";
        cout << getName() << " is not scary, but hardworking, so he'll be a diligent student (will read all the books)." << endl;
        books_read.assign(course.getTotalNumberofBooks(), true); // Resize the vector and fill with true values
        // cout<< books_read[0] << " "<< books_read[1] <<endl;
    }

    // If the student is not scary and not hard working then he fails
    else {
        type = "Failure";
        cout << getName() << " is not scary and not hardworking, so a failure." << endl;
        books_read.clear(); // Clear the vector
    }
}

// Define the setter function for the academic year
void Student::SetYear(){
        ac_year++;
        cout<< getName() << " is now in year " << ac_year << " at Monsters University."<< endl;
}


// Define Scare ability, book is an optional argument
/**
 * @brief Sets the scare level of the student based on the given book and the student's characteristics.
 * 
 * If the student is reading a scaring book, the scare level increases.
 * If the student already has a natural ability to scare, the scare level remains the same.
 * If the student is not scary, the scare level is set to 0.
 * 
 * @param book The book being read by the student.
 */
void Student::SetScare(Book book){

        // if the student is reading a scaring book then scare levels up
        if (hasBook && book.getGenre() == "Scaring"){
                // scare ++;
                scare += 0.5; 
                cout<< getName() << " improved scaring ability! "<< "Scare ability is now worth " << scare << (scare == 1 ? " point!" : " points!")<< endl;
        }

        // Set initial scare level based on Monster attributes, you only benefit from natural ability once
        else if (isScary && ac_year < 2){
                cout<< getName() << " is already scary."<< endl;

                if (getSize() == "large"){
                        scare = 2.5;
                        cout<< getName() << " has a natural ability to scare !" << " Scare ability is worth " << scare << " points !"<< endl;
                }
                else if (getFeature() != "none"){
                        scare = 2; // if the monster has a scary feature then scare ability is worth 2 more points
                        cout<< getName() << " has a natural scary feature!" << " Scare ability is now  worth " << scare << " points !"<< endl;
                }
        }

        // If the student is not scary then scare ability is 0
        else if (!isScary)
                cout<< getName() << " is not scary, "<< getPronoun(false) <<" needs to learn to be scary, starts with 0 scare points."<< endl;
        
};

// Define learning function
/**
 * @brief Represents the learning process of a student.
 * 
 * If the student is in the first year or has passed the previous year, they can learn.
 * The function iterates through the book stack and reads the books based on the student's reading behaviour represnted by vector books_read
 * After reading each book, the student's scare ability is improved.
 * The function keeps track of the number of books read and provides summary output.
 * If the student has not passed the previous year, they cannot learn.
 *
 * @param stack The book stack from which the student reads books.
 */
void Student::learn(BookStack stack){
        // initiate learning process

        // cout<< "Size of stack is : " << stack.getNumber()<<endl;
        // cout<<"Academic year "<< ac_year << " at Monsters University."<<endl;
        // cout<<"Pass = " <<year_passes[0] << year_passes[1] << year_passes[2] << endl;

        // If the student is in the first year or has passed the previous year then he can learn
        if (ac_year == 1 || year_passes[ac_year - 2])
        {
        cout<< getName() << " is learning to be a Scarer."<< endl;
        int n = stack.getNumber();
        int cnt = 0;
        for (int i = 0; i < n; i++){
                // cout<< i << " books_read = " << books_read.size()<<endl;
                // Update if he chooses to read the book
                if (books_read[i]){
                        cnt++;

                        // Mike reads a new book
                        read();

                        // We present the book Mike is reading
                        stack.getBookinStack(i).describe();
                        
                        // Mike improves his scaring ability after reading this book
                        SetScare(stack.getBookinStack(i));

                        // Mike finishes reading the book
                        read();

                        // Store which books have been read
                        books_read[i] = true;

                        // The book is removed from the stack
                        // stack.pop();
                        cout<< endl;
                }
        }
        if (cnt == 0)
                cout<< getName() << " did not read any books."<<endl;
        else if (cnt < n)
                cout<< getName() << " read some ("<< cnt<<"/"<<n<<") of the books."<<endl;
        else
                cout<< getName() << " read all the books."<<endl;
        }

        // If the student has not passed the previous year then he cannot learn
        else
                return;
}

// Define the passing function
/**
 * @brief Checks if the student has passed the current academic year based on their scare ability.
 * 
 * @return true if the student has passed the current academic year, false otherwise.
 */
bool Student::pass(){
        switch(ac_year){
                
        // Scare ability needed to pass the first year
        case 1:
                if (scare >= 1){
                        year_passes[ac_year-1] = true;
                        cout<< getName() << " has passed the "<< ac_year<<" year."<<endl;
                        SetYear(); // Moves to next year
                        return true;
                }
                else{
                        cout<< getName() << " has not passed the "<< ac_year<<" year."<<endl;
                        year_passes[ac_year-1] = false;
                        return false;
                }
        // Scare ability needed to pass the second year
        case 2:
                if (scare >= 2){
                        year_passes[ac_year-1] = true;
                        cout<< getName() << " has passed the "<< ac_year<<" year."<<endl;
                        SetYear(); // Moves to next year
                        return true;
                }
                else{
                        cout<< getName() << " has not passed the "<< ac_year<<" year."<<endl;
                        year_passes[ac_year-1] = false;
                        return false;
                }
        
        // Scare ability needed to pass the second year
        case 3:
                if (scare >= 3){
                        cout << "Congratulations, " << getName() <<", you finished all 3 years!" << endl;
                        year_passes[ac_year - 1] = true;
                        return true;
                }
                else{
                        cout << "Sorry, " << getName() << ", you did not pass your final year." << endl;
                        year_passes[ac_year - 1] = false;
                        return false;
                }
        }
        cerr<< "Error: Academic year not found."<<endl;
        exit(1);
}
#endif