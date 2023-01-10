// ------------------------------------------------ hashtable.cpp -----------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/08/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Implementation for hashtable
// --------------------------------------------------------------------------------------------------------------------

//Notes: 
// -------------------------------------------------------------------------------------------------------------------- 

#include <string>
#include <iostream>
#include "hashtable.h"

using namespace std;

//Constructor
//Precondition: Nothing
//Postcondition: Creates a blank slate for the hash table
HashTable::HashTable()
{
	for (int i = 0; i < MAX; i++)
		table[i] = nullptr;
}

//Reads the list of customer and creates table
//Precondition: File must be formatted correctly
//Postcondition: Creates a fully implemented hash table
void HashTable::readCustomerList(ifstream& file)
{
	int id;
	string first, last;
	Customer* newCustomer;

	while (file >> id >> last >> first)
	{
		newCustomer = new Customer();
		newCustomer->setCustomer(id, last, first);

		insert(newCustomer, id);
		newCustomer = nullptr;
	}
}

//Inserts a customer into the hash table
//Precondition: Nothing
//Postcondition: Customer object gets added into the hash table
void HashTable::insert(Customer* data, int id)
{
	int index = id % MAX;
	if (table[index] == nullptr)
		table[index] = data;
	else
	{
		data->setNext(table[index]);
		table[index] = data;
	}

}

//Finds a customer given the id
//Precondition: Nothing
//Postcondition: Returns bool depending on if the customer was found or not
bool HashTable::find(int id)
{
	int index = id % MAX;
	Customer* curPtr = nullptr;

	if (table[index] == nullptr)
		return false;
	else
		curPtr = table[index];

	while (curPtr != nullptr)
	{
		if (curPtr->getId() == id)
			return true;
		curPtr = curPtr->getNext();
	}

	return false;
}

//Retrieves a pointer to the customer for further use
//Precondition: Nothing
//Postcondition: Either returns a customer pointer or nullptr depending on if the customer exists
Customer* HashTable::retrieve(int id)
{
	Customer* curPtr = table[0];
	for (int i = 0; i < MAX; i++)
	{
		curPtr = table[i];
		while (curPtr != nullptr && curPtr->getId() != id)
		{
			curPtr = curPtr->getNext();
		}
		if (curPtr == nullptr)
			continue;
		if (curPtr->getId() == id)
			break;
	}
	return curPtr;
}