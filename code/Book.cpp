/**
 * @file Book.cpp
 * @brief Implementation file for the Book class.
 */
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

/**
 * @brief Default constructor for the Book class.
 */
Book::Book() {;}

/**
 * @brief Constructor for the Book class.
 * @param _title The title of the book.
 * @param _author The author of the book.
 * @param _color The color of the book.
 * @param _genre The genre of the book.
 * @param _pages The number of pages in the book.
 */
Book::Book(string _title, string _author, string _color, string _genre, int _pages) : title(_title), author(_author), color(_color), genre(_genre), pages(_pages) {}

/**
 * @brief Getter function for the title attribute.
 * @return The title of the book.
 */
string Book::getTitle() { return title; }

/**
 * @brief Getter function for the author attribute.
 * @return The author of the book.
 */
string Book::getAuthor() { return author; }

/**
 * @brief Getter function for the color attribute.
 * @return The color of the book.
 */
string Book::getColor() { return color; }

/**
 * @brief Getter function for the genre attribute.
 * @return The genre of the book.
 */
string Book::getGenre() { return genre; }

/**
 * @brief Getter function for the pages attribute.
 * @return The number of pages in the book.
 */
int Book::getPages() { return pages; }

/**
 * @brief Prints a description of the book.
 */
void Book::describe() {
    cout << "The book is called " << title << " and is written by " << author << ". " << endl;
    cout << "The book is " << color << " and is a " << genre << " book with " << pages << " pages. " << endl;
}

