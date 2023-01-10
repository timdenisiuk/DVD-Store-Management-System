// ------------------------------ moviefactory.h ----------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Moviefactory header file
// --------------------------------------------------------------------------------

// Notes:
// --------------------------------------------------------------------------------

#pragma once
#include <string>
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"

using namespace std;

class MovieFactory
{
    public:

        static Movie* createMovie(string);

};