// ------------------------------------------------ buisness.h --------------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Header file for overall buisness class
// --------------------------------------------------------------------------------------------------------------------

//Notes:
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include "hashtable.h"
#include "bstree.h"
#include "transaction.h"
#include <iostream>

using namespace std;

class Business
{
	public:

		void buildMovies(ifstream&);
		void buildCustomers(ifstream&);
		void processTrans(ifstream&);

	private:

		HashTable* hashTable;
		Transaction t;
		BSTree tree;
		BSTree* classic;
		BSTree* comedy;
		BSTree* drama;
};