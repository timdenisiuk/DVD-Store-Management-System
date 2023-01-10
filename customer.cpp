// ------------------------------------------------ customer.cpp ------------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Implementation for individual customers
// --------------------------------------------------------------------------------------------------------------------

//Notes: Assumption is made that given file is formatted correctly
// -------------------------------------------------------------------------------------------------------------------- 

#include "customer.h"
#include <iostream>
#include <climits>

using namespace std;

//Constructor for customer
//Precondition: Nothing
//Postcondition: Creates a new customer object with default data
Customer::Customer()
{
	custId = INT_MIN;
	lastName = "";
	firstName = "";
	nextCustomer = nullptr;

}

//Sets customer data based on extracted data
//Precondition: Nothing
//Postcondition: Sets the data within the customer object given the parameters
void Customer::setCustomer(int id, string last, string first)
{
	custId = id;
	lastName = last;
	firstName = first;
}

//Displays the data for customer
//Precondition: Nothing
//Postcondition: Outputs data to console
void Customer::display()
{
	cout << "Id: " << custId << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "First Name: " << firstName << endl;
}

//Calls the TransHistory object to add a node
//Precondition: Nothing
//Postcondition: Adds a transaction to the customer
void Customer::addTrans(string type, string name, int year)
{
	history.insert(type, name, year);
}

//Calls the TransHistory object to output all transactions
//Precondition: Nothing
//Postcondition: Outputs all transaction history data to console
void Customer::getHistory()
{
	history.showHistory();
}

//Sets the next pointer for the customer in the hash table
//Precondition: Customer must already be defined
//Postcondition: Sets the next pointer to the new customer
void Customer::setNext(Customer* next)
{
	nextCustomer = next;
}

//Returns the next customer, used for traversal
//Precondition: Nothing
//Postcondition: Returns customer pointer
Customer* Customer::getNext()
{
	return nextCustomer;
}

//Returns ID data
//Precondition: Nothing
//Postcondition: Returns id in the form of an int
int Customer::getId()
{
	return custId;
}

//Returns last name
//Precondition: Nothing
//Postcondition: returns last name in the form of a string
string Customer::getLast()
{
	return lastName;
}

//Returns first name
//Precondition: Nothing
//Postcondition: returns first name in the form of a string
string Customer::getFirst()
{
	return firstName;
}

//Inserts a transaction node into the transHistory object
//Precondition: Nothing
//Postcondition: Inserts node into individual customers transHistory object
void TransList::insert(string type, string name, int year)
{
	TransNode* newNode = new TransNode(type, name, year);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

//Shows all transactions for a customer
//Precondition: Nothing
//Postcondtiion: Outputs all transactions for an individual customer
void TransList::showHistory()
{
	TransNode* curPtr = head;
	while (curPtr != nullptr)
	{
		cout << "Transaction Type: " << curPtr->transType << endl << "Movie Name: " << curPtr->movieName << endl
			<< "Release Date: " << curPtr->year << endl << endl;
		curPtr = curPtr->next;
	}
}