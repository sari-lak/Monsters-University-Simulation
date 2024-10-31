/**
 * @file BookStack.cpp
 * @brief Implementation file for the BookStack class.
 * 
 * This file contains the implementation of the BookStack class, which represents a stack of books.
 * It includes the constructor, destructor, getter functions, action functions, and utility functions.
 */

#include <iostream>
#include "Book.h"
#include "BookStack.h"
using namespace std;

/**
 * @brief Constructs a new instance of the BookStack class.
 */
BookStack::BookStack() {;};

/**
 * @brief Constructs a BookStack object with the specified number and initializes the top index to -1.
 * 
 * @param n The number of books in the stack.
 */
BookStack::BookStack(int n) : number(n), top(-1) {};

/**
 * @brief Destructor for the BookStack class.
 * 
 * This destructor is responsible for cleaning up any resources allocated by the BookStack class.
 * It does not take any parameters and does not return a value.
 */
BookStack::~BookStack(){;};

// Define the simple getter functions
/**
 * @brief Retrieves the number of books in the book stack.
 * 
 * @return The number of books in the book stack.
 */
int BookStack::getNumber(){return number;}

/**
 * Retrieves the title of a book at the specified index.
 *
 * @param i The index of the book.
 * @return The title of the book at the specified index.
 */
string BookStack::getTitle(int i){return books[i].getTitle();}

/**
 * @brief Represents a book in the stack.
 */
Book BookStack::getBookinStack(int i){
    if (i <= top){
        return books[i];
    }
    else
        cerr<< "Book not found in the stack."<<endl;
        exit(1);
}

/**
 * Prints all the books in the stack.
 */
void BookStack::getAllBooksinStack(){
    cout<< "Books in the stack: ";
    for (int i = 0; i <= top; i++){
        cout << "'"<< books[i].getTitle()<<"'"<<" ";
        if (i < top){
            cout<<", ";
        }
    }
    cout<<"."<<endl;
}

/**
 * @brief Checks if a book is present in the book stack.
 * 
 * @param _book The book to be checked.
 * @return true if the book is present in the stack, false otherwise.
 */
bool BookStack::CheckBookinStack(Book& _book){
    for (int i = 0; i <= top; i++){
        if (books[i].getTitle() == _book.getTitle()){
            return true;
        }
    }
    return false;
}

/**
 * Returns the index of a book in the stack.
 * 
 * @param _book The book to search for.
 * @return The index of the book in the stack, or -1 if the book is not found.
 */
int BookStack::GetBookIndex(Book& _book){
    for (int i = 0; i <= top; i++){
        if (books[i].getTitle() == _book.getTitle()){
            return i;
        }
    }
    cerr<< "Book not found in the stack."<<endl;
    return -1;
}

// Implementation of the action functions
/**
 * @brief Pushes a book onto the stack.
 * 
 * This function pushes a book onto the stack. If the stack is full, it displays an error message and exits the program.
 * 
 * @param b The book to be pushed onto the stack.
 */
void BookStack::push(Book& b) {
    if (top < number - 1) {
        top++;
        books.push_back(b);
        cout << "Book pushed onto the stack." << endl;
    } 
    else{
        cerr << "Stack overflow! Cannot push more books onto the stack." << endl;
        exit(0); // Exit the program due to stack overflow
    }
}

/**
 * @brief Replaces a book in the stack with another book.
 * 
 * This function replaces a book in the stack with another book. If the book to be replaced is not found in the stack, it displays an error message and exits the program.
 * 
 * @param _book1 The book to be replaced.
 * @param _book2 The book to replace _book1.
 * @return A reference to the BookStack object.
 */
BookStack& BookStack::replace(Book& _book1, Book& _book2){
    if (CheckBookinStack(_book1)){
        int index = GetBookIndex(_book1);
        books[index] = _book2;
        cout << "Book "<< _book1.getTitle()<<" replaced in the stack with " << _book2.getTitle() << endl;
        return *this;
    }
    else{
        cerr << "Book not in Stack!" << endl;
        exit(0); // Exit the program due to stack overflow
    }
}

/**
 * @brief Pops a book from the stack.
 * 
 * This function pops a book from the stack. If the stack is empty, it displays an error message.
 */
void BookStack::pop() {
    if (!books.empty()) {
        books.erase(books.begin());
        top--;
    } 
    else {
        cerr << "Stack underflow! Cannot pop a book from an empty stack." << endl;
    }
}

/**
 * @brief Creates a stack of books from a vector of books.
 * 
 * This function creates a stack of books from a vector of books. It pushes each book onto the stack.
 * 
 * @param books The vector of books.
 * @return A reference to the BookStack object.
 */
BookStack& BookStack::createStack(vector <Book>& books){
    cout<< "Creating a stack of books..."<<endl;
    int n = books.size();
    for (int i = 0; i < n; i++){
        push(books[i]);
    }
    return *this;
}