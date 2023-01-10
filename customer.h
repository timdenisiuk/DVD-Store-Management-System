// ------------------------------------------------ customer.h --------------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Header file for both customer and transaction list for customer
// --------------------------------------------------------------------------------------------------------------------

//Notes:
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include <string>

using namespace std;

class TransList
{
	friend class Customer;
	struct TransNode
	{
		explicit TransNode(string type, string name, int y) : transType(type), movieName(name), year(y), next(nullptr) {};
		string transType;
		string movieName;
		int year;
		TransNode* next;
	};

	TransNode* head;
	void insert(string type, string name, int year);
	void showHistory();

};

class Customer
{
public:
	Customer();
	void setCustomer(int, string, string);
	void display();
	void addTrans(string, string, int);
	void getHistory();
	void setNext(Customer*);
	Customer* getNext();
	int getId();
	string getLast();
	string getFirst();

	TransList history;

private:
	Customer* nextCustomer;


	int custId;
	string lastName;
	string firstName;


};