// --------------------------------- comedy.cpp -----------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Implementation for the Comedy Movie object
// --------------------------------------------------------------------------------

// Notes: Inherited from the movie class
// --------------------------------------------------------------------------------

#include "comedy.h"
#include <iostream>

using namespace std;

//Comedy constructor
//Precondition: None
//Postcondition: Creates a comedy movie object with the corresponding values
Comedy::Comedy(string g, int s, string d, string t, int y)
{
    this->genre = g;
    this->stock = s;
    this->director = d;
    this->title = t;
    this->releaseYear = y;
}

//Overloaded == operator
//Precondition: Comedy object exists
//Postcondition: Returns a boolean for equality
bool Comedy::operator==(const Movie& rhs) const
{
    if (this->title != rhs.getTitle()) return false;
    if (this->director != rhs.getDirector()) return false;
    if (this->releaseYear != rhs.getReleaseYear()) return false;
    return true;
}

//Overloaded != operator
//Precondition: Comedy object exists
//Postcondition: Returns a boolean for inequality
bool Comedy::operator!=(const Movie& rhs) const
{
    return !(*this == rhs);
}

//Overloaded < operator
//Precondition: Comedy object exists
//Postcondition: Returns a boolean for less than
bool Comedy::operator<(const Movie& rhs) const
{
    if (this->title < rhs.getTitle())
    {
        return true;
    }

    else if (this->title == rhs.getTitle())
    {
        if (this->releaseYear < rhs.getReleaseYear())
        {
            return true;
        }
    }

    return false;
}

//Overloaded > operator
//Precondition: Comedy object exists
//Postcondition: Returns a boolean for greater than
bool Comedy::operator>(const Movie& rhs) const
{
    if (this->title > rhs.getTitle())
    {
        return true;
    }

    else if (this->title == rhs.getTitle())
    {
        if (this->releaseYear > rhs.getReleaseYear())
        {
            return true;
        }
    }

    return false;
}