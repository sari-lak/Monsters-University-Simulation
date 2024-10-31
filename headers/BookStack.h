#ifndef BOOKSTACK_H
#define BOOKSTACK_H
#include <iostream>
#include <vector>
#include "Book.h"
using namespace std;

// Furthe enhancement: Use dynamic memory allocation to define the size of the book stack at runtime
class BookStack{
private:
    int number;
    // Book *books;
    vector <Book> books;
    int top;

public:
    // Default constructor (empty bookstack with 0 books)
    BookStack();

    // Declare constructor with parameter
    BookStack(int);

    // Declare destructor
    ~BookStack();

    // Declare simple getter functions
    int getNumber();
    string getTitle(int);
    Book getBookinStack(int);

    // Declare other getter functions
    bool CheckBookinStack(Book&);
    int GetBookIndex(Book&);
    void getAllBooksinStack();

    // Declare action functions
    void push(Book&);
    BookStack& replace(Book&, Book&);
    void pop();
    BookStack& createStack(vector <Book>&);
};
#endif // BOOKSTACK_H