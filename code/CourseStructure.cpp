/**
 * @file CourseStructure.cpp
 * @brief Implementation file for the CourseStructure class.
 */
#include <iostream>
#include "CourseStructure.h"
#include "BookStack.h"
#include <vector>

/**
 * @brief Constructs a CourseStructure object with the given vector of books.
 * 
 * This constructor creates a course structure for each academic year based on the given vector of books.
 * It calculates the number of books per stack assuming an even distribution and assigns the remaining books to the last year.
 * It then creates a stack for each academic year and populates it with the corresponding number of books.
 * Finally, it adds the stack to the course structure for that academic year.
 * 
 * @param books The vector of books to be used for creating the course structure.
 */
CourseStructure::CourseStructure(vector<Book>& books){
    // Create course structure for each academic year
    int n = books.size();
    int num_stacks = 3; // Assuming 3 academic years

    // Calculate the number of books per stack (assuming even distribution)
    int books_per_stack = n / num_stacks;
    int remaining_books = n % num_stacks; // All these added to last year

    int book_index = 0;

    for (int i = 0; i < num_stacks; ++i) {
        // Determine the number of books for this stack
        int stack_books = books_per_stack + (i < remaining_books ? 1 : 0);

        // Create a stack for each academic year
        BookStack year_stack(stack_books);

        // Populate the stack with books
        vector<Book> stack_books_vec;
        for (int j = 0; j < stack_books; ++j) {
            stack_books_vec.push_back(books[book_index++]);
        }

        // Create the stack with the books for this year
        year_stack.createStack(stack_books_vec);

        // Add the stack to the course structure for that academic year
        bookStacks[i].push_back(year_stack);

        // Print the stack
        cout<< "Stack "<<i<<" created with "<<stack_books<<(stack_books == 1 ? " book." : " books.")<<endl;
        cout<< endl;
    }
}

/**
 * @brief Returns the BookStack objects for a specific academic year.
 * 
 * This function returns the BookStack objects for the specified academic year.
 * 
 * @param year The academic year for which to retrieve the BookStack objects.
 * @return The vector of BookStack objects for the specified academic year.
 */
vector<BookStack> CourseStructure::getBookStacks(AcademicYear year){
    return bookStacks[year];
}

/**
 * @brief Returns the number of stacks in the course structure.
 * 
 * This function returns the number of stacks in the course structure.
 * 
 * @return The number of stacks in the course structure.
 */
int CourseStructure::getNumberofStacks(){
    return bookStacks->size();
}

/**
 * @brief Returns the number of books in a specific stack.
 * 
 * This function returns the number of books in the specified academic year's stack.
 * 
 * @param year The academic year for which to retrieve the number of books.
 * @return The number of books in the specified academic year's stack.
 */
int CourseStructure::getNumberofBooks(AcademicYear year){
    return bookStacks[year].back().getNumber();
}

/**
 * @brief Returns the total number of books in the course structure.
 * 
 * This function returns the total number of books in the course structure by summing up the number of books in each stack.
 * 
 * @return The total number of books in the course structure.
 */
int CourseStructure::getTotalNumberofBooks(){
    // get the number of books in the course
    int total_books =   getNumberofBooks(CourseStructure::FIRST_YEAR) + 
                        getNumberofBooks(CourseStructure::SECOND_YEAR) + 
                        getNumberofBooks(CourseStructure::THIRD_YEAR);
    return total_books;
}

/**
 * @brief Returns the academic year as a string.
 * 
 * This function returns the academic year as a string based on the value of the AcademicYear enum.
 * 
 * @return The academic year as a string.
 */
string CourseStructure::getAcademicYear(AcademicYear year){
    if (year == AcademicYear::FIRST_YEAR){
        cout<< "This is the first year at Monsters University."<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        return "First Year";
    }
    else if (year == AcademicYear::SECOND_YEAR){
        cout<< "This is the second year at Monsters University."<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        return "Second Year";
    }
    else if(year == AcademicYear::THIRD_YEAR){
        cout<< "This is the third year at Monsters University."<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        return "Third Year";
    }
    else{
        cerr<< "Invalid academic year."<<endl;
        exit(1);
    }
}

