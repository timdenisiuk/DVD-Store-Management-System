// ------------------------------------------------ transaction.cpp ---------------------------------------------------

// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/08/2021
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Implementation for hashtable
// --------------------------------------------------------------------------------------------------------------------

//Notes: 
// -------------------------------------------------------------------------------------------------------------------- 

#include <iostream>
#include <sstream>
#include <string>
#include "transaction.h"
#include "bstree.h"
#include "hashtable.h"
#include "business.h"



using namespace std;

//Dummy method that only sets up for other polymorphed classes
//Precondition: Nothing
//Postcondition: Outputs error, but not used
void Transaction::doTrans(HashTable& hash, BSTree& tree, string trans)
{
	cout << "Invalid Command. Skipping transaction." << endl << endl;
}

//Base class for Transaction, only used for error messages
//Precondition: Nothing
//Postcondition: Notifies user that data is not valid
void Transaction::setData()
{
	cout << "Invalid Data. Skipping transaction." << endl << endl;
}

//Factory method for transaction
//Precondition: Nothing
//Postcondition: Returns a pointer to the type of transaction needed
Transaction* Transaction::factoryMethod(string type)
{
	if (type == "B")
		return new Borrow;

	else if (type == "R")
		return new Return;

	else if (type == "H")
		return new History;

	else if (type == "I")
		return new Show;

	else
		return new Transaction;
}

//Adds transaction to customer, and alters movie count
//Precondition: Nothing, should be called if everything is valid
//Postcondition: Alters customer data and BST movie data
void Borrow::doTrans(HashTable& hash, BSTree& tree, string trans)
{
	string transType, mediaType, movieType, title, director, actor, input;
	char genre = trans[9];
	int releaseYear, releaseMonth, id;
	istringstream iss(trans);
	iss >> transType >> id;

	if (hash.find(id) == false) //Checking if ID is valid
	{
		display();
		return;
	}

	iss >> mediaType;

	if (mediaType != "D")	//Checking if media type is valid
	{
		display();
		return;
	}

	iss >> movieType;	//Grabbing genre

	if (movieType == "F")
	{
		iss >> input;

		while (input.back() != ',')	//Iterates while there isn't a comma to grab full title
		{
			title.append(input);
			title.append(" ");
			iss >> input;
		}

		input.pop_back();		//Gets rid of comma
		title.append(input);
		iss >> releaseYear;

		tree.updateStock(tree, genre, transType[0], trans);		//Updates stock on tree

		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);	//Grabs movie pointer for data for transaction
		
		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}

	else if (movieType == "D")			
	{
		iss >> input;

		while (input.back() != ',')		//Iterates while there isn't a comma to grab full director
		{
			director.append(input);
			director.append(" ");
			iss >> input;
		}

		input.pop_back();	//Gets rid of comma
		director.append(input);

		iss >> input;

		while (input.back() != ',')	//Iterates while there isn't a comma to grab full title
		{
			title.append(input);
			title.append(" ");
			iss >> input;
		}

		input.pop_back();	//Gets rid of comma
		title.append(input);
		
		tree.updateStock(tree, genre, transType[0], trans);		//Updates stock on tree

		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);

		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}

	else if (movieType == "C")
	{
		iss >> releaseMonth >> releaseYear;

		while (iss >> input)
		{
			actor.append(input);
			actor.append(" ");
		}

		tree.updateStock(tree, genre, transType[0], trans);		//Updates stock on tree

		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);

		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}
	else
		display();
}


//Used to throw error message
//Precondition: Something must be wrong in the file
//Postcondition: Displays message in console
void Borrow::display()
{
	cout << "Invalid Data. Skipping transaction." << endl << endl;
}


//Adds transaction to transaction history of customer, same logic as borrow
//Precondition: Nothing
//Postcondition: Alters movie data and adds transaction to transaction history for customer
void Return::doTrans(HashTable& hash, BSTree& tree, string trans)
{
	string transType, mediaType, movieType, title, director, actor, input;
	char genre = trans[9];
	int releaseYear, releaseMonth, id;
	istringstream iss(trans);
	iss >> transType >> id;

	if (hash.find(id) == false)
	{
		display();
		return;
	}

	iss >> mediaType;

	if (mediaType != "D")
	{
		display();
		return;
	}

	iss >> movieType;

	if (movieType == "F")
	{
		iss >> input;

		while (input.back() != ',')
		{
			title.append(input);
			title.append(" ");
			iss >> input;
		}

		input.pop_back();
		title.append(input);
		iss >> releaseYear;

		tree.updateStock(tree, genre, transType[0], trans);
		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);

		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}

	else if (movieType == "D")
	{
		iss >> input;

		while (input.back() != ',')
		{
			director.append(input);
			director.append(" ");
			iss >> input;
		}

		input.pop_back();
		director.append(input);

		iss >> input;

		while (input.back() != ',')
		{
			title.append(input);
			title.append(" ");
			iss >> input;
		}

		input.pop_back();
		title.append(input);

		tree.updateStock(tree, genre, transType[0], trans);
		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);

		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}

	else if (movieType == "C")
	{
		iss >> releaseMonth >> releaseYear;

		while (iss >> input)
		{
			actor.append(input);
			actor.append(" ");
		}



		tree.updateStock(tree, genre, transType[0], trans);
		Movie* mov = tree.retrieveMovie(tree, genre, transType[0], trans);

		if (mov == nullptr)
		{
			display();
			return;
		}

		Customer* cust = hash.retrieve(id);
		cust->addTrans(transType, mov->getTitle(), mov->getReleaseYear());
	}
	else
		display();

}


//Throws error message for when data is invalid
//Precondition: Data in text file at some point needs to be invalid
//Postcondition: Throws error message in console
void Return::display()
{
	cout << "Invalid Data. Skipping transaction." << endl << endl;
}

//Goes through each movie and give stock info for each movie
//Precondition: Nothing
//Postcondition: Outputs all movie data for single tree
void Show::doTrans(HashTable& hash, BSTree& tree, string trans)
{
	tree.printInorder();
	cout << endl;
}

//Shows history of the customer
//Precondition: Nothing
//Postcondition: Shows transaction history of each customer from most recent to least recent
void History::doTrans(HashTable& h, BSTree& tree, string trans)
{
	string dummy; int id;
	istringstream iss(trans);
	iss >> dummy >> id;

	if (h.find(id) == false)
		cout << "Invalid ID. Skipping transaction." << endl;

	else
	{
		Customer* c = h.retrieve(id);
		cout << "Name: " << c->getFirst() << " " << c->getLast() << endl << "ID: " << c->getId() << endl
			<< "Transaction History:" << endl;
		c->getHistory();
		cout << endl;
	}
}
