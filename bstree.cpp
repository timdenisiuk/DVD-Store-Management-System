// --------------------------------- bstree.cpp -----------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: HashTable assignment BSTree implementation for storing movies.
// --------------------------------------------------------------------------------

// Notes: 
// --------------------------------------------------------------------------------

#include "bstree.h"
#include <iostream>
#include <sstream>

using namespace std;

//BSTree constructor that sets root to nullptr
//Precondition: None
//Postcondition: Creates a tree object with root as nullptr
BSTree::BSTree() : root{ nullptr } {}

//Takes a Movie pointer and calls a recursive method to insert it into a BSTree
//Precondition: Movie pointer must exist
//Postcondition: Calls insertHelper
void BSTree::insert(Movie* movie) {
	return insertHelper(this->root, movie);
}

//Recursive insertHelper that inserts movie into the tree
//Precondition: Movie pointer must exist
//Postcondition: Movie pointer inserted into tree
void BSTree::insertHelper(Node*& curr, Movie* movie) {

	// If current node is null, dynamically create new Node
	// and assign movie.
	if (curr == nullptr) {
		curr = new Node;
		curr->left = nullptr;
		curr->right = nullptr;
		curr->data = movie;
	}

	// If same movie is found, increase stock.
	else if (*curr->data == *movie) {
		curr->data->setStock(movie->getStock() + curr->data->getStock());
	}

	// If movie is < curr node movie, 
	// go left recursively.
	else if (*curr->data > *movie) {
		insertHelper(curr->left, movie);
	}

	// If movie > curr node movie, 
	// go right recursively.
	else if (*curr->data < *movie) {
		insertHelper(curr->right, movie);
	}

}

//Calls the recursive helper method, printInorderHelper
//Precondition: Tree must exist
//Postcondition: Calls recursive method printInorderHelper
void BSTree::printInorder()
{
	printInorderHelper(this->root);
}

//Recusive method that traverses the tree inorder and displays its contents
//Precondition:
//Postcondition:
void BSTree::printInorderHelper(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	printInorderHelper(node->left);
	node->data->display();
	printInorderHelper(node->right);

}

//Method that works with the trasaction class to update the stock 
//Precondition: Tree must exist and command string properly formatted
//Postcondition: Calls the corresponding genre tree to updating
void BSTree::updateStock(BSTree& tree, char genre, char transType, string trans)
{

	// Switch case that calls the corresponding method for updating stock
	switch (genre)
	{
		case 'C':
		{
			int month, year;
			string first, last, actor;

			// Appends string with pertinent information and assigning
			// to corresponding data type
			istringstream iss(trans.substr(10, trans.length() - 1));
			iss >> month >> year >> first >> last;
			actor = first + " " + last;

			tree.updateClassic(year, actor, this->root, transType);
			break;
		}

		case 'D':
		{
			string director = trans.substr(11, trans.find(',') - 11);

			// Appended string
			string appStr = trans.substr(trans.find(',') + 2, trans.length());
			string title = appStr.substr(0, appStr.find(','));

			tree.updateDrama(director, title, this->root, transType);
			break;
		}

		case 'F':
		{
			string title = trans.substr(11, trans.find(',') - 11);
			int year = stoi(trans.substr(trans.find(',') + 1, trans.length() - 1));

			tree.updateComedy(title, year, this->root, transType);
			break;
		}

		default:
		{
			break;
		}
	}
}

//Updating stock for Classic movies when borrowed or returned
//Precondition: Classic tree exists
//Postcondition: Updated stock for returned and borrowed movies.
void BSTree::updateClassic(int year, string actor, Node* curr, char transType)
{
	if (curr == nullptr)
	{
		return;
	}

	updateClassic(year, actor, curr->left, transType);

	if (curr->data->getReleaseYear() == year && curr->data->getActor() == actor)
	{	
		// If transaction type is return, add 1 to stock
		if (transType == 'R')
		{
			curr->data->setStock(curr->data->getStock() + 1);
			return;
		}

		// Borrowing subtracts 1 from stock
		if (curr->data->getStock() >= 1 && transType == 'B')
		{
			curr->data->setStock(curr->data->getStock() - 1);
			return;
		}

		// If stock is 0, print error message and return
		else if (curr->data->getStock() < 1 && transType == 'B')
		{
			cout << "Insufficient stock. Skipping transaction." << endl << endl;
			return;
		}
	}

	updateClassic(year, actor, curr->right, transType);
}

//Updating stock for Comedy movies when borrowed or returned
//Precondition: Comedy tree exists
//Postcondition: Updated stock for returned and borrowed movies.
void BSTree::updateComedy(string title, int year, Node* curr, char transType)
{
	if (curr == nullptr)
	{
		return;
	}

	updateComedy(title, year, curr->left, transType);

	if (curr->data->getTitle() == title && curr->data->getReleaseYear() == year)
	{
		// If transaction type is return, add 1 to stock
		if (transType == 'R')
		{
			curr->data->setStock(curr->data->getStock() + 1);
			return;
		}

		// Borrowing subtracts 1 from stock
		if (curr->data->getStock() >= 1 && transType == 'B')
		{
			curr->data->setStock(curr->data->getStock() - 1);
			return;
		}

		// If stock is 0, print error message and return
		else if (curr->data->getStock() < 1 && transType == 'B')
		{
			cout << "Insufficient stock. Skipping transaction." << endl << endl;
			return;
		}
	}

	updateComedy(title, year, curr->right, transType);
}

//Updating stock for Drama movies when borrowed or returned
//Precondition: Drama tree exists
//Postcondition: Updated stock for returned and borrowed movies
void BSTree::updateDrama(string director, string title, Node* curr, char transType)
{
	if (curr == nullptr)
	{
		return;
	}

	updateDrama(director, title, curr->left, transType);

	if (curr->data->getDirector() == director & curr->data->getTitle() == title)
	{
		// If transaction type is return, add 1 to stock
		if (transType == 'R')
		{
			curr->data->setStock(curr->data->getStock() + 1);
			return;
		}

		// Borrowing subtracts 1 from stock
		if (curr->data->getStock() >= 1 && transType == 'B')
		{
			curr->data->setStock(curr->data->getStock() - 1);
			return;
		}

		// If stock is 0, print error message and return
		else if (curr->data->getStock() < 1 && transType == 'B')
		{
			cout << "Insufficient stock. Skipping transaction." << endl << endl;
			return;
		}
	}

	updateDrama(director, title, curr->right, transType);
}

//Method for determining which retrieve method to call for genre
//Precondition: Trasaction is properly formatted
//Postcondition: Returns pointer
Movie* BSTree::retrieveMovie(BSTree& tree, char genre, char transType, string trans)
{
	switch (genre)
	{
		case 'C':
		{
			int month, year;
			string first, last, actor;
			istringstream iss(trans.substr(10, trans.length() - 1));
			iss >> month >> year >> first >> last;
			actor = first + " " + last;
			return returnClassic(year, actor, this->root, transType);
			break;
		}

		case 'D':
		{
			string director = trans.substr(11, trans.find(',') - 11);
			string appStr = trans.substr(trans.find(',') + 2, trans.length());
			string title = appStr.substr(0, appStr.find(','));
			return tree.returnDrama(director, title, this->root, transType);
			break;
		}

		case 'F':
		{
			string title = trans.substr(11, trans.find(',') - 11);
			int year = stoi(trans.substr(trans.find(',') + 1, trans.length() - 1));
			return tree.returnComedy(title, year, this->root, transType);
			break;
		}

		default:
		{
			break;
		}
	}

	return nullptr;
}

//Returns a classic movie pointer for transactions
//Precondition: Classic tree exists
//Postcondition: Returns pointer
Movie* BSTree::returnClassic(int year, string actor, Node* curPtr, char TransType)
{
	if (curPtr == nullptr)
		return nullptr;

	while (curPtr->data->getReleaseYear() != year)
	{
		if (curPtr->data->getReleaseYear() > year)
			curPtr = curPtr->left;

		else if (curPtr->data->getReleaseYear() < year)
			curPtr = curPtr->right;

		if (curPtr == nullptr) 
			break;
	}

	if (curPtr == nullptr) 
		return nullptr;

	if (curPtr->data->getActor() != actor)
	{
		while (curPtr->data->getActor() != actor)
		{
			if (curPtr->data->getActor() > actor)
				curPtr = curPtr->left;

			else if (curPtr->data->getTitle() < actor)
				curPtr = curPtr->right;

			if (curPtr == nullptr)
				break;
		}
	}

	if (curPtr == nullptr) 
		return nullptr;

	return curPtr->data;
}

//Returns a comedy movie pointer for transactions
//Precondition: Comedy tree exists
//Postcondition: Returns pointer
Movie* BSTree::returnComedy(string title, int year, Node* curPtr, char transType)
{
	if (curPtr == nullptr)
		return nullptr;

	while (curPtr->data->getTitle() != title)
	{
		if (curPtr->data->getTitle() > title)
			curPtr = curPtr->left;

		else if (curPtr->data->getTitle() < title)
			curPtr = curPtr->right;

		if (curPtr == nullptr)
			break;
	}

	if (curPtr == nullptr)
		return nullptr;

	if (curPtr->data->getReleaseYear() != year)
	{
		while (curPtr->data->getReleaseYear() != year)
		{
			if (curPtr->data->getReleaseYear() > year)
				curPtr = curPtr->left;

			else if (curPtr->data->getReleaseYear() < year)
				curPtr = curPtr->right;

			if (curPtr == nullptr)
				break;
		}
	}

	if (curPtr == nullptr)
		return nullptr;

	return curPtr->data;
}

//Returns a drama movie pointer for transactions
//Precondition: Drama tree exists
//Postcondition: Returns pointer
Movie* BSTree::returnDrama(string director, string title, Node* curPtr, char transType)
{
	if (curPtr == nullptr)
		return nullptr;

	while (curPtr->data->getDirector() != director)
	{
		if (curPtr->data->getDirector() > director)
			curPtr = curPtr->left;

		else if (curPtr->data->getDirector() < director)
			curPtr = curPtr->right;

		if (curPtr == nullptr)
			break;
	}

	if (curPtr == nullptr)
		return nullptr;

	if (curPtr->data->getTitle() != title)
	{
		while (curPtr->data->getTitle() != title)
		{
			if (curPtr->data->getTitle() > title)
				curPtr = curPtr->left;

			else if (curPtr->data->getTitle() < title)
				curPtr = curPtr->right;

			if (curPtr == nullptr)
				break;
		}
	}

	if (curPtr == nullptr)
		return nullptr;

	return curPtr->data;
}