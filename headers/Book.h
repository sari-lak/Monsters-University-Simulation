#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

// Declaration of the Book class
class Book{
private:
    string title;
    string author;
    string color;
    string genre;
    int pages;

public:
    // Default Constructor
    Book();

    //Constructor for the Book class
    Book(string _title, string _author, string _color, string _genre, int _pages);

    // Declare the getter functions for the Book attributes
    string getTitle() ;
    string getAuthor() ;
    string getColor() ;
    string getGenre() ;
    int getPages() ;

    // Declare the action functions
    void describe();
};

#endif // BOOK_H
