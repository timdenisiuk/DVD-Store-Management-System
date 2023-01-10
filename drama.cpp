// --------------------------------- drama.cpp ------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Implementation for the Drama Movie object
// --------------------------------------------------------------------------------

// Notes: Inherited from the movie class
// --------------------------------------------------------------------------------

#include "drama.h"
#include <iostream>

using namespace std;

//Drama constructor
//Precondition: None
//Postcondition: Creates a Drama movie object with the corresponding values
Drama::Drama(string g, int s, string d, string t, int y)
{
    this->genre = g;
    this->stock = s;
    this->director = d;
    this->title = t;
    this->releaseYear = y;
}

//Overloaded == operator
//Precondition: Drama object exists
//Postcondition: Returns a boolean for equality
bool Drama::operator==(const Movie& rhs) const
{
    if (this->title != rhs.getTitle()) return false;
    if (this->director != rhs.getDirector()) return false;
    if (this->releaseYear != rhs.getReleaseYear()) return false;

    return true;
}

//Overloaded != operator
//Precondition: Drama object exists
//Postcondition: Returns a boolean for inequality
bool Drama::operator!=(const Movie& rhs) const
{
    return !(*this == rhs);
}

//Overloaded < operator
//Precondition: Drama object exists
//Postcondition: Returns a boolean for less than
bool Drama::operator<(const Movie& rhs) const
{
    if (this->director < rhs.getDirector())
    {
        return true;
    }

    else if (this->director == rhs.getDirector())
    {
        if (this->title < rhs.getTitle())
        {
            return true;
        }
    }

    return false;
}

//Overloaded > operator
//Precondition: Drama object exists
//Postcondition: Returns a boolean for greater than
bool Drama::operator>(const Movie& rhs) const
{
    if (this->director > rhs.getDirector())
    {
        return true;
    }

    else if (this->director == rhs.getDirector())
    {
        if (this->title > rhs.getTitle())
        {
            return true;
        }
    }

    return false;
}