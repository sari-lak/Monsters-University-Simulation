/**
 * @file Monster.cpp
 * @brief Implementation file for the Monster class.
 */

#include <iostream>
#include <string>
#include "Monster.h"
#include "Student.h"
#include "CourseStructure.h"
using namespace std;

/**
 * @brief Default constructor for the Monster class.
 */
Monster::Monster() {};

/**
 * @brief Constructs a Monster object with the given parameters.
 * 
 * @param _name The name of the monster.
 * @param _color The color of the monster.
 * @param _gender The gender of the monster.
 * @param _skin The skin type of the monster.
 * @param _size The size of the monster.
 * @param _feature The distinguishing feature of the monster.
 * @param _nbEyes The number of eyes the monster has.
 * @param _nbArms The number of arms the monster has.
 * @param _nbLegs The number of legs the monster has.
 * @param _hasTail Indicates whether the monster has a tail or not.
 * @param _isScary Indicates whether the monster is scary or not.
 * @param _hasBook Indicates whether the monster has a book or not.
 * @param _isSitting Indicates whether the monster is sitting or not.
 */
Monster::Monster(Characters _name, Colors _color, Genders _gender, Skins _skin, Sizes _size, Features _feature, 
                 int _nbEyes, int _nbArms, int _nbLegs, 
                 bool _hasTail, bool _isScary, bool _hasBook, bool _isSitting) 
    : name(_name), color(_color), gender(_gender), skin(_skin), size(_size), feature(_feature), 
      nbEyes(_nbEyes), nbArms(_nbArms), nbLegs(_nbLegs), 
      hasTail(_hasTail), isScary(_isScary), hasBook(_hasBook), isSitting(_isSitting) {}

// Define the getter functions for the Monster attributes
/**
 * @brief Get the name of the Monster.
 * @return The name of the Monster as a string.
 */
string Monster::getName() {return CharactersToString(name);}

/**
 * @brief Get the color of the Monster.
 * @return The color of the Monster as a string.
 */
string Monster::getColor() {return ColorsToString(color);}

/**
 * @brief Get the gender of the Monster.
 * @return The gender of the Monster as a string.
 */
string Monster::getGender() {return GendersToString(gender);}

/**
 * @brief Get the skin type of the Monster.
 * @return The skin type of the Monster as a string.
 */
string Monster::getSkin() {return SkinsToString(skin);}

/**
 * @brief Get the size of the Monster.
 * @return The size of the Monster as a string.
 */
string Monster::getSize() {return SizesToString(size);}

/**
 * @brief Get the feature of the Monster.
 * @return The feature of the Monster as a string.
 */
string Monster::getFeature() {return FeaturesToString(feature);}

/**
 * @brief Get the number of eyes of the Monster.
 * @return The number of eyes of the Monster.
 */
int Monster::getnbEyes(){return nbEyes;}

/**
 * @brief Get the number of arms of the Monster.
 * @return The number of arms of the Monster.
 */
int Monster::getnbArms(){return nbArms;}

/**
 * @brief Get the number of legs of the Monster.
 * @return The number of legs of the Monster.
 */
int Monster::getnbLegs(){return nbLegs;}

/**
 * @brief Check if the Monster has a tail.
 * @return True if the Monster has a tail, false otherwise.
 */
bool Monster::gethasTail(){return hasTail;}

/**
 * @brief Check if the Monster is scary.
 * @return True if the Monster is scary, false otherwise.
 */
bool Monster::getisScary(){return isScary;}

/**
 * @brief Check if the Monster has a book.
 * @return True if the Monster has a book, false otherwise.
 */
bool Monster::gethasBook(){return hasBook;}

/**
 * @brief Check if the Monster is sitting.
 * @return True if the Monster is sitting, false otherwise.
 */
bool Monster::getisSitting(){return isSitting;}

/**
 * @brief Get the pronoun of the Monster.
 * @param capital Whether to capitalize the pronoun or not (default is false).
 * @return The pronoun of the Monster as a string.
 */
string Monster::getPronoun(bool capital=false){
        string p;
        if (gender == Monster::Genders::male){
            p = "he";}
        else{
            p = "she";}
        if (capital){
            p[0] = toupper(p[0]);
        }
        return p;
    }

/**
 * @brief Describe the Monster.
 */
void Monster::describe(){
    cout<< CharactersToString(name) << " is "<< SizesToString(size) << ", " << SkinsToString(skin) << " and "<< ColorsToString(color) << "."<<endl;//" monster."<<endl;
    cout<< getPronoun(true) <<" has " << nbEyes << (nbEyes == 1 ? " eye" : " eyes" )<< ", " << nbArms << (nbArms == 1 ? " arm" : " arms" )<< ", " << nbLegs << (nbLegs == 1 ? " leg" : " legs" )<< " and"<< (hasTail ? " a tail" : " no tail" ) << "." << endl;
}

/**
 * @brief Make the Monster sit.
 */
void Monster::sit() {
    if (!isSitting) {
        cout << " is now sitting. ";
        isSitting = true;
        } 
    else 
        cout << " is sitting. ";
    }

/**
 * @brief Make the Monster read a book.
 */
void Monster::read() {
    if (!hasBook) {
        cout << CharactersToString(name) << " is reading a new book !"<<endl;
        hasBook = true;
        } 
    else {
        cout << CharactersToString(name) << " finished reading. "<<endl;
        hasBook = false;
    }
    }

// Define the admission function
/**
 * @brief Admit the Monster to Monsters University.
 * @param course The course structure of Monsters University.
 * @return The Student object representing the admitted Monster.
 */
Student Monster::admit(CourseStructure course) {

    // declare a zero vector of length nb_books_in_course
    // THESE VECTOR SIZES ARE NOT MAINTAINED OUTSIDE THIS FUNCTION
    vector <bool> books_read(course.getTotalNumberofBooks(), false);
    vector <bool> year_passes(3, false);
    // check if the monster is a human, only monsters become students
    if (getnbEyes() == 2 && 
        getnbArms() == 2 && 
        getnbLegs() == 2 &&
        getSkin() == "hairless" &&
        gethasTail() == false) {
        cerr<< getName() << " is a Human! Rejected for admission to Monsters University. "<<endl;
        return Student();
    }
    else{
        cout << getName() << " has been accepted to Monsters University! "<<endl;

        Student student(name, color, gender, skin, size, feature, 
                        getnbEyes(), getnbArms(), getnbLegs(), 
                        gethasTail(), getisScary(), gethasBook(), getisSitting(),
                        0, "Student", year_passes, books_read, 0); // Student attributes

        return student;
    }
}

// Define the utility functions

/**
 * @brief Convert the Characters enum value to a string.
 * @param name The Characters enum value.
 * @return The string representation of the Characters enum value.
 */
string Monster::CharactersToString(Monster::Characters name) {
    switch (name) {
    case Characters::Mike: return "Mike";
    case Characters::Sully: return "Sully";
    case Characters::Randall: return "Randall";
    case Characters::Boo: return "Boo";
    default: return "Unknown";
    }
}

/**
 * @brief Convert the Colors enum value to a string.
 * @param color The Colors enum value.
 * @return The string representation of the Colors enum value.
 */
string Monster::ColorsToString(Monster::Colors color) {
    switch (color) {
    case Colors::red: return "red";
    case Colors::blue: return "blue";
    case Colors::green: return "green";
    case Colors::yellow: return "yellow";
    case Colors::purple: return "purple";
    case Colors::orange: return "orange";
    case Colors::pink: return "pink";
    case Colors::black: return "black";
    case Colors::white: return "white";
    case Colors::brown: return "brown";
    case Colors::grey: return "grey";
    default: return "Unknown";
    }
}

/**
 * @brief Convert the Genders enum value to a string.
 * @param gender The Genders enum value.
 * @return The string representation of the Genders enum value.
 */
string Monster::GendersToString(Monster::Genders gender) {
    switch (gender) {
    case Genders::male: return "male";
    case Genders::female: return "female";
    case Genders::nonbinary: return "nonbinary";
    default: return "Unknown";
    }
}

/**
 * @brief Convert the Skins enum value to a string.
 * @param skin The Skins enum value.
 * @return The string representation of the Skins enum value.
 */
string Monster::SkinsToString(Monster::Skins skin) {
    switch (skin) {
    case Skins::furry: return "furry";
    case Skins::scaly: return "scaly";
    case Skins::feathery: return "feathery";
    case Skins::hairless: return "hairless";
    default: return "Unknown";
    }
}

/**
 * @brief Convert the Sizes enum value to a string.
 * @param size The Sizes enum value.
 * @return The string representation of the Sizes enum value.
 */
string Monster::SizesToString(Monster::Sizes size) {
    switch (size) {
    case Sizes::small: return "small";
    case Sizes::medium: return "medium";
    case Sizes::large: return "large";
    default: return "Unknown";
    }
}

/**
 * @brief Convert the Features enum value to a string.
 * @param feature The Features enum value.
 * @return The string representation of the Features enum value.
 */
string Monster::FeaturesToString(Monster::Features feature) {
    switch (feature) {
    case Features::none: return "none";
    case Features::horns: return "horns";
    case Features::wings: return "wings";
    case Features::fluffy: return "fluffy";
    case Features::invisibility: return "invisibility";
    default: return "Unknown";
    }
}