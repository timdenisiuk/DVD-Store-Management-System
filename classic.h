// --------------------------------- classic.h ------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Classic header file
// --------------------------------------------------------------------------------

// Notes: Inherited from the movie class
// --------------------------------------------------------------------------------

#pragma once
#include "movie.h"
#include <string>

using namespace std;

class Classic : public Movie
{
    public:

        Classic(string g, int s, string t, string d, string a, int rY, int rM);

        bool operator==(const Movie&) const;
        bool operator!=(const Movie&) const;
        bool operator<(const Movie&) const;
        bool operator>(const Movie&) const;
};