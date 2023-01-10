// --------------------------------- movie.h --------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: Movie header file
// --------------------------------------------------------------------------------

// Notes: Parent class of the Classic, Comedy, and Drama movie classes
// --------------------------------------------------------------------------------

#pragma once
#include <string>

using namespace std;

class Movie
{
    public:

        Movie();

        virtual bool operator==(const Movie&) const;
        virtual bool operator!=(const Movie&) const;
        virtual bool operator<(const Movie&) const;
        virtual bool operator>(const Movie&) const;

        void setGenre(char);
        void setStock(int);
        void setDirector(string);
        void setTitle(string);
        void setMajorActor(string, string);
        void setReleaseDate(int, int);
        void setReleaseYear(int);

        string getGenre() const;
        int getStock() const;
        string getTitle() const;
        string getDirector() const;
        string getActor() const;
        int getReleaseYear() const;
        int getReleaseMonth() const;

        virtual void display();

    protected:

        string genre;
        int stock;
        string title;
        string director;
        string actor;
        int releaseYear;
        int releaseMonth;
};