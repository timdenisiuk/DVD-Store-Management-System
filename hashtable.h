// ------------------------------------------------ hashtable.h -------------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/08/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Header file for hash table
// --------------------------------------------------------------------------------------------------------------------

//Notes: 
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "customer.h"
using namespace std;

class HashTable
{
	public:

		HashTable();
		void readCustomerList(ifstream&);
		void insert(Customer*, int);
		bool find(int);
		Customer* retrieve(int);

	private:

		static const int MAX = 11;
		Customer* table[MAX];

};