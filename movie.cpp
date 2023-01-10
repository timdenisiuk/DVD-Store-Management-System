// --------------------------------- movie.cpp ------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Implementation for the Movie object
// --------------------------------------------------------------------------------

// Notes: Parent class of the Classic, Comedy, and Drama movie classes
// --------------------------------------------------------------------------------

#include "movie.h"
#include <iostream>

using namespace std;

//Classic constructor
//Precondition: None
//Postcondition: Creates a classic movie object with the corresponding values
Movie::Movie()
{
    releaseMonth = 0;
    releaseYear = 0;
    stock = 0;
}

//Overloaded operator, placeholder for virtual method
//Precondition: Movie object exists
//Postcondition: Returns true
bool Movie::operator==(const Movie& rhs) const
{
    return true;
}

//Overloaded operator, placeholder for virtual method
//Precondition: Movie object exists
//Postcondition: Returns true
bool Movie::operator!=(const Movie& rhs) const
{
    return true;
}

//Overloaded operator, placeholder for virtual method
//Precondition: Movie object exists
//Postcondition: Returns true
bool Movie::operator<(const Movie& rhs) const
{
    return true;
}

//Overloaded operator, placeholder for virtual method
//Precondition: Movie object exists
//Postcondition: Returns true
bool Movie::operator>(const Movie& rhs) const
{
    return true;
}

//Sets the genre of a movie object
//Precondition: Movie object exists
//Postcondition: Genre updated
void Movie::setGenre(char genre)
{
    this->genre = genre;
}

//Sets the stock of a movie object
//Precondition: Movie object exists
//Postcondition: stock updated
void Movie::setStock(int stock)
{
    this->stock = stock;
}

//Sets the director of a movie object
//Precondition: Movie object exists
//Postcondition: Director updated
void Movie::setDirector(string director)
{
    this->director = director;
}

//Sets the title of a movie object
//Precondition: Movie object exists
//Postcondition: Title updated
void Movie::setTitle(string title)
{
    this->title = title;
}

//Sets the major actor of a movie object
//Precondition: Movie object exists
//Postcondition: Major actor updated
void Movie::setMajorActor(string first, string last)
{
    this->actor = first + " " + last;
}

//Sets the release date of a movie object
//Precondition: Movie object exists
//Postcondition: release date updated
void Movie::setReleaseDate(int year, int month)
{
    this->releaseYear = year;
    this->releaseMonth = month;
}

//Returns the genre of a movie object
//Precondition: Movie object exists
//Postcondition: Genre returned
string Movie::getGenre() const
{
    return this->genre;
}

//Returns the stock of a movie object
//Precondition: Movie object exists
//Postcondition: Stock returned
int Movie::getStock() const
{
    return this->stock;
}

//Returns the title of a movie object
//Precondition: Movie object exists
//Postcondition: Title returned
string Movie::getTitle() const
{
    return this->title;
}

//Returns the director of a movie object
//Precondition: Movie object exists
//Postcondition: director returned
string Movie::getDirector() const
{
    return this->director;
}

//Returns the actor of a movie object
//Precondition: Movie object exists
//Postcondition: Actor returned
string Movie::getActor() const
{
    return this->actor;
}

//Returns the release year of a movie object
//Precondition: Movie object exists
//Postcondition: Release year returned
int Movie::getReleaseYear() const
{
    return this->releaseYear;
}

//Returns the release month of a movie object
//Precondition: Movie object exists
//Postcondition: Release month returned
int Movie::getReleaseMonth() const
{
    return this->releaseMonth;
}

//Prints the movie information
//Precondition: Movie object exists
//Postcondition: Prints information to screen
void Movie::display()
{
    // Printing classic movie. Information structured differently.
    if (this->genre == "C")
    {
        cout << this->genre << ", " << this->stock << ", " << this->director << ", "
            << this->title << ", " << this->actor << ", " << this->releaseMonth << ", "
            << this->releaseYear << endl;
    }
    
    // Printing other comedy and drama movies
    else
    {
        cout << this->genre << ", " << this->stock << ", " << this->director << ", "
            << this->title << ", " << this->releaseYear << endl;
    }
}