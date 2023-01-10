// --------------------------------- drama.h --------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Drama header file
// --------------------------------------------------------------------------------

// Notes: Inherited from the movie class
// --------------------------------------------------------------------------------

#pragma once
#include "movie.h"
#include <string>

using namespace std;

class Drama : public Movie
{
public:

    Drama();
    Drama(string g, int s, string d, string t, int y);
    ~Drama();

    bool operator==(const Movie&) const;
    bool operator!=(const Movie&) const;
    bool operator<(const Movie&) const;
    bool operator>(const Movie&) const;
};