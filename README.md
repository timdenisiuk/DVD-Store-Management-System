# CSS 343 Final Project: DVD Store Management System

## Project Overview

The purpose of this project is to create a management system for a hypothetical DVD rental. When giving a text file containing a bunch of
data, we need to process this data in a database written in C++. Relational databases like MySQL could not be used here, so finding
how to store this data was on us to figure out. This project involved the use of polymorphism in different movie types, as well as
out own hash table for storing information on customers. We also needed to use a tree for storing data about our movies, like our stock.

## Project Description

The project has three major portions to it, storing movie data, storing movie inventory data, and storing customer rental data. 
To control this, we have a file called buisness.cpp that performs these major processes. 

The first process is reading customer data. To start, with our given text file, we parse through the information, creating a new
customer object for each one. For each customer object, we use a hash formula to insert our customer into our hash table. Each
customer also has a linked list associated to it, which allows for the traversal of each customer object in the hash table.

The next process is to build our movies. To do this, we create three different binary search trees, each associated with different
movie genres. After this, we parse through the text information file on each movie, and we insert these movie objects
into our tree. To insert and compare movies, we need to overload some operators so that we are able to
retrieve these movies based on their release year.

The final process is to process transactions. This incorperates both the movies and customer data. 
For each transaction, we first need to verify that the customer we are looking for exists. We then check for
our media type, in which our only option is "D" for DVD. Once we move past this, we look for the movie
genre and movie name and release date. If everything is valid, we change the values in both the customer and
the movie tree to reflect on our transaction type, whether it be borrowing or returning a movie. At any point
if we find that there is an invalid piece of information, we through a error message and continue with the
input file.
