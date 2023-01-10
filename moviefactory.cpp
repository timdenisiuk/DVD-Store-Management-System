// ---------------------------- moviefactory.cpp ----------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Implementation for the moviefactory class
// --------------------------------------------------------------------------------

// Notes: Factory method to instantiate objects of the movie classes
// --------------------------------------------------------------------------------

#include "moviefactory.h"
#include <iostream>

using namespace std;

//Creates a movie object
//Precondition: None
//Postcondition: Creates a movie of the correct genre and data
Movie* MovieFactory::createMovie(string line)
{
    string str1 = line;
    string str2;
    string genre, director, title;
    string first, last, actor;
    int stock;
    int month;
    int year;

    genre = str1.substr(0, str1.find(','));
    str2 = str1.substr(str1.find(',') + 2, str1.length() - 1);

    stock = stoi(str2.substr(0, str2.find(',')));
    str1 = str2.substr(str2.find(',') + 2, str2.length() - 1);

    switch (genre[0]) {

        case 'C':
        {
            director = str1.substr(0, str1.find(','));
            str2 = str1.substr(str1.find(',') + 2, str1.length() - 1);

            title = str2.substr(0, str2.find(','));
            str1 = str2.substr(str2.find(',') + 2, str2.length() - 1);

            first = str1.substr(0, str1.find(' '));
            str2 = str1.substr(str1.find(' ') + 1, str1.length() - 1);

            last = str2.substr(0, str2.find(' '));
            str1 = str2.substr(str2.find(' ') + 1, str2.length() - 1);

            actor = first + " " + last;

            month = stoi(str1.substr(0, str1.find(' ')));
            str2 = str1.substr(str1.find(' ') + 1, str1.length() - 1);
            year = stoi(str2.substr(0, str2.find(' ')));

            return new Classic(genre, stock, title, director, actor, year, month);
            break;
        }

        case 'F':
        {
            director = str1.substr(0, str1.find(','));
            str2 = str1.substr(str1.find(',') + 2, str1.length() - 1);

            title = str2.substr(0, str2.find(','));
            str1 = str2.substr(str2.find(',') + 2, str2.length() - 1);

            year = stoi(str1.substr(0, str1.find(' ')));

            return new Comedy(genre, stock, director, title, year);
            break;
        }

        case 'D':
        {
            director = str1.substr(0, str1.find(','));
            str2 = str1.substr(str1.find(',') + 2, str1.length() - 1);

            title = str2.substr(0, str2.find(','));
            str1 = str2.substr(str2.find(',') + 2, str2.length() - 1);

            year = stoi(str1.substr(0, str1.find(' ')));

            return new Drama(genre, stock, director, title, year);
            break;
        }

        default:
        {
            break;
        }
    }

    return NULL;
}