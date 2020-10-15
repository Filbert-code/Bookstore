// Author: Alex Filbert
// Date: 10/10/2020
// Course: CS 300B
// Assignment: Homework 2
#ifndef BOOKSTOREMANAGER_H
#define BOOKSTOREMANAGER_H
#include "Book.h"

using namespace std;

class BookstoreManager
{
    private:
        // private member variables
        Book *books; // Book array
        int size;
        int capacity;

    public: 
        BookstoreManager(); // default constructor
        bool isEmpty(); // returns true if the Book array is empty 
        bool isFull(); // returns true if the Book array is full
        void listSize(); // prints the size of the Book array
        void print(); // prints the Book array to the console
        void insert(Book &book); // adds to the Book array in sorted order
        void remove(Book &book); // deletes entries of the Book array
        void removePublisher(string &pub); // deteles all instances with the same publisher
        void search(Book &book); // finds and prints the book with the specified ISBN 
};

#endif