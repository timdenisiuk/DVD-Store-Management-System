#include "bstree.h"
#include "business.h"
#include "movie.h"
#include "moviefactory.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Business b;

	// Reading data for movies
	ifstream infile1("data4movies.txt");
	b.buildMovies(infile1);

	ifstream infile2("data4customers.txt");
	b.buildCustomers(infile2);

	ifstream infile3("data4commands.txt");
	b.processTrans(infile3);

	return 0;
}