// ------------------------------------------------ transaction.h -----------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/08/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Header file for transaction
// --------------------------------------------------------------------------------------------------------------------

//Notes: Holds both base transaction and polymorphed transactions
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include "hashtable.h"
#include "bstree.h"
using namespace std;

class TransData
{
public:
	explicit TransData() : month(0), year(0), transType(""), director(""), actor("") {};
	int month;
	int year;
	string transType;
	string director;
	string actor;
};

class Transaction
{
public:
	virtual void doTrans(HashTable&, BSTree&, string);
	virtual void setData();
	static Transaction* factoryMethod(string);
protected:
	HashTable* h;

};

class Borrow : public Transaction
{
public:
	void doTrans(HashTable&, BSTree&, string);
	void display();
private:
};

class Return : public Transaction
{
public:
	void doTrans(HashTable&, BSTree&, string);
	void display();
private:
};

class Show : public Transaction
{
public:
	void doTrans(HashTable&, BSTree&, string);
private:
};

class History : public Transaction
{
public:
	void doTrans(HashTable&, BSTree&, string);
};