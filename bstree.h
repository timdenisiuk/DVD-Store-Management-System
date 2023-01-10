// --------------------------------- bstree.h -------------------------------------
// Name and Class: Tim Denisiuk, Michael Cho CSS 343
// Creation Date: 05/21/2021
// Last Modified: 06/09/2021
// --------------------------------------------------------------------------------

// Purpose: BSTree header file
// --------------------------------------------------------------------------------

// Notes: 
// --------------------------------------------------------------------------------

#pragma once
#include "movie.h"
using namespace std;

class BSTree
{	
	private:

		struct Node
		{
			Movie* data;
			Node* left;
			Node* right;
		};

		Node* root;

		void insertHelper(Node*&, Movie*);
		void printInorderHelper(Node*);

	public:

		BSTree();
		void insert(Movie*);
		void printInorder();
		
		void updateStock(BSTree&, char, char, string);
		void updateClassic(int, string, Node*, char);
		void updateComedy(string, int, Node*, char);
		void updateDrama(string, string, Node*, char);

		Movie* retrieveMovie(BSTree&, char, char, string);
		Movie* returnClassic(int, string, Node*, char);
		Movie* returnComedy(string, int, Node*, char);
		Movie* returnDrama(string, string, Node*, char);
};