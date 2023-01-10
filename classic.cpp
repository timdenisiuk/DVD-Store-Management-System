// --------------------------------- classic.cpp ----------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Implementation for the Classic Movie object
// --------------------------------------------------------------------------------

// Notes: Inherited from the movie class
// --------------------------------------------------------------------------------

#include "classic.h"
#include <iostream>

using namespace std;

//Classic constructor
//Precondition: None
//Postcondition: Creates a classic movie object with the corresponding values
Classic::Classic(string g, int s, string t, string d, string a, int rY, int rM)
{
    this->genre = g;
    this->stock = s;
    this->title = t;
    this->director = d;
    this->actor = a;
    this->releaseYear = rY;
    this->releaseMonth = rM;
}

//Overloaded == operator
//Precondition: Classic object exists
//Postcondition: Returns a boolean for equality
bool Classic::operator==(const Movie& rhs) const
{
    if (this->title != rhs.getTitle()) return false;
    if (this->director != rhs.getDirector()) return false;
    if (this->releaseYear != rhs.getReleaseYear()) return false;
    if (this->releaseMonth != rhs.getReleaseMonth()) return false;
    if (this->actor != rhs.getActor()) return false;

    return true;
}

//Overloaded != operator
//Precondition: Classic object exists
//Postcondition: Returns a boolean for inequality
bool Classic::operator!=(const Movie& rhs) const
{
    return !(*this == rhs);
}

//Overloaded < operator
//Precondition: Classic object exists
//Postcondition: Returns a boolean for less than
bool Classic::operator<(const Movie& rhs) const
{
    if (this->releaseYear < rhs.getReleaseYear())
    {
        return true;
    }

    else if (this->releaseYear == rhs.getReleaseYear())
    {
        if (this->releaseMonth < rhs.getReleaseMonth())
        {
            return true;
        }

        else if (this->releaseMonth == rhs.getReleaseMonth())
        {
            if (this->actor < rhs.getActor())
            {
                return true;
            }
        }
    }

    return false;
}

//Overloaded > operator
//Precondition: Classic object exists
//Postcondition: Returns a boolean for greater than
bool Classic::operator>(const Movie& rhs) const
{
    if (this->releaseYear > rhs.getReleaseYear())
    {
        return true;
    }

    else if (this->releaseYear == rhs.getReleaseYear())
    {
        if (this->releaseMonth > rhs.getReleaseMonth())
        {
            return true;
        }
        
        else if (this->releaseMonth == rhs.getReleaseMonth())
        {
            if (this->actor > rhs.getActor())
            {
                return true;
            }
        }
    }

    return false;
}