// ------------------------------------------------ business.cpp --------------------------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Implementation of overall business dealings
// --------------------------------------------------------------------------------------------------------------------

//Notes: Assumption is made that given file is formatted correctly
// -------------------------------------------------------------------------------------------------------------------- 

#include <iostream>
#include <sstream>
#include "business.h"
#include "transaction.h"
#include "bstree.h"
#include "movie.h"
#include "moviefactory.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"

using namespace std;

//Takes customer file and builds a hash table that stores all customers
//Precondition: Customer text file must be formatted correctly
//Postcondition: Buisness has a hash table that has all customer data
void Business::buildCustomers(ifstream& infile1)
{
	hashTable = new HashTable();
	hashTable->readCustomerList(infile1);
}

//Creates different trees to store different movie genres
//Precondition: Movie text file must be formatted correctly
//Postcondition: Buisness has three different trees for three different genres
void Business::buildMovies(ifstream& infile1)
{
	string line;
	string genre;
	classic = new BSTree();
	comedy = new BSTree();
	drama = new BSTree();

	while (!infile1.eof()) {
		getline(infile1, line);
		if (infile1.eof()) break;

		genre = line.substr(0, line.find(','));

		switch (genre[0]) {
		case 'C':
		{
			classic->insert(MovieFactory::createMovie(line));
			break;
		}
		case 'F':
		{
			comedy->insert(MovieFactory::createMovie(line));
			break;
		}
		case 'D':
		{
			drama->insert(MovieFactory::createMovie(line));
			break;
		}
		default:
		{
			cout << "Invalid genre type " << genre << ". Skipping movie entry." << endl << endl;
			break;
		}
		}
	}
}

//Process all transactions and alters data when needed
//Precondition: File must be formatted correctly
//Postcondition: Adds transaction data to customers, alters movie stock, and displays info when necessary
void Business::processTrans(ifstream& infile1)
{
	Transaction* base;
	string genre;

	string transaction, transType;
	while (!infile1.eof())
	{
		getline(infile1, transaction);
		istringstream iss(transaction);
		if (transaction == "")
			break;
		iss >> transType;
		base = base->factoryMethod(transType);

		if (transType == "I") {
			base->doTrans(*hashTable, *classic, transaction);
			base->doTrans(*hashTable, *comedy, transaction);
			base->doTrans(*hashTable, *drama, transaction);
		}
		else if (transType == "B" || transType == "R")
		{
			genre = transaction.substr(9, 1);

			switch (genre[0])
			{
			case 'C':
			{
				base->doTrans(*hashTable, *classic, transaction);
				break;
			}
			case 'F':
			{
				base->doTrans(*hashTable, *comedy, transaction);
				break;
			}
			case 'D':
			{
				base->doTrans(*hashTable, *drama, transaction);
				break;
			}
			default:
			{
				cout << "Invalid genre type. Skipping transaction." << endl << endl;
				break;
			}
			}
		}
		else if (transType == "H")
		{
			base->doTrans(*hashTable, tree, transaction);
		}
		else
		{
			cout << "Invalid transaction type: " << transType << ". Skipping transaction." << endl << endl;
		}

	}

}