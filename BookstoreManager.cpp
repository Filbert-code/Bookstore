// Author: Alex Filbert
// Date: 10/10/2020
// Course: CS 300B
// Assignment: Homework 2
#include "BookstoreManager.h"
#include <iostream>

// BookstoreManager default constructor
BookstoreManager::BookstoreManager()
{
    size = 0;
    capacity = 5;
    books = new Book[capacity];
}

// Returns and prints true if the books array is empty
bool BookstoreManager::isEmpty()
{
    if(size == 0)
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return size == 0;
}

// Returns and prints true if the books array is full
bool BookstoreManager::isFull()
{
    if(size == capacity)
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return size == capacity;
}

// prints the number of books in the Bookstore
void BookstoreManager::listSize()
{
    cout << "Number of Books in the Bookstore: "<< size << endl;
}

/*
    Inserts a Book object into the the BookstoreManager's Book array in 
    sorted ascending order. 
*/
void BookstoreManager::insert(Book &book)
{
    size++; // increment the Book array
    if(size >= capacity)
    {
        capacity *= 2;
        Book *temp = new Book[capacity];
        // make a temporary array to transfer the data to the new array
        for(int i = 0; i < size; ++i)
            temp[i] = books[i];
        delete[] books; // delete insufficient array
        // create the new books array with double the previous capacity
        books = new Book[capacity];
        for(int i = 0; i < size; ++i)
            books[i] = temp[i];
        delete[] temp; // delete temporary array
    }

    int index = 0; // index that will determine where to insert the new Book 
    // comparing Book isbn fields until insertion location is found
    while(book.getIsbn() > books[index].getIsbn())
    {
        index++;
        // adds the Book to the end of the array if found to be largest value
        if(index > size - 1)
        {
            books[size - 1] = book;
            return;
        }
    }

    // shifting all elements once to the right of the found insertion point
    for(int i = size - 1; i >= index; --i)
    {
        books[i + 1] = books[i];
    }
    books[index] = book; // inserting the Book

}

/*
    Prints the contents of the books array
*/
void BookstoreManager::print()
{
    for(int i = 0; i < size; ++i)
        cout << books[i]; // Book overloaded insertion operator used here
}

/*
    deletes the Book object with the same 'isbn' attribute as 
    the given Book argument. The given Book argument is constructed
    using it's 1-arg constructor.
*/
void BookstoreManager::remove(Book &book)
{
    // looping through the books array
    for(int i = 0; i < size; ++i)
    {
        // true if Book argument's isbn matches the array element's
        if(books[i].getIsbn() == book.getIsbn())
        {
            // removes the Book if it's the last element 
            if(i == size - 1)
            {
                --size;
                return;
            }
            // shift the remaining array elements to the right
            for(int k = size - 1; k > i; --k)
            {
                books[k - 1] = books[k];
                --size;
            }
            return;
        }
    }
    cout << "Not Found" << endl;
}

/*
    Deletes all instances of Book objects from the Book array that
    have the same publisher as the given argument. 
*/
void BookstoreManager::removePublisher(string &pub)
{
    int numOfRemovals = 0; // tracks total books to remove
    // replaces every book that needs to be removed with a new Book with 'isbn' of -1
    for(int i = 0; i < size; ++i)
    {
        if(books[i].getPublisher() == pub)
        {
            // later we can tell that this book should not be copied
            // to the new array because of it's 'isbn' value
            books[i] = Book("title", -1, "authors", "publisher");
            numOfRemovals++;
        }
    }

    // create a temporary array to store the new Book array 
    Book *temp = new Book[size - numOfRemovals];
    // makes sure to avoid copying over a Book with 'isbn' of -1
    int shiftCount = 0; 
    // fill the temp array
    for(int i = 0; i < size - numOfRemovals; ++i)
    {
        while(books[i + shiftCount].getIsbn() == -1)
            shiftCount++;
        temp[i] = books[i + shiftCount];
    }

    delete[] books; // delete current books array
    size -= numOfRemovals; 
    books = new Book[size];
    // refill the books array with the updated array values
    for(int k = 0; k < size; ++k)
    {
        books[k] = temp[k];
    }
    delete[] temp; // get rid of the temporary array
}

/*
    Using binary search to find the Book corresponding to the 'isbn'
    number of the given Book argument.
*/
void BookstoreManager::search(Book &book)
{
    int isbn = book.getIsbn();
    // variables that keep track of beginning, ending, and middle array indices
    int high = size - 1, low = 0, mid;
    while(low < high)
    {
        // get index of Book in the middle of the array
        mid = (high + low) / 2;
        // check if the Book isbn is less than the given argument
        if(books[mid].getIsbn() < isbn)
            low = mid + 1; // keep the top half of the array
        else 
            high = mid; // keep the bottom half of the array
    }
    // print out whether the book was found or not
    if(low == high && books[low].getIsbn() == isbn)
        cout << books[low];
    else
        cout << "Book not found.";
}