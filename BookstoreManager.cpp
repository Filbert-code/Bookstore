#include "BookstoreManager.h"
#include <iostream>

BookstoreManager::BookstoreManager()
{
    size = 0;
    capacity = 1;
    books = new Book[capacity];
}

void BookstoreManager::insert(Book &book)
{
    if(size >= capacity)
    {
        capacity *= 2;
        Book *temp = new Book[capacity];
        // make a temporary array to transfer the data to the new array
        for(int i = 0; i < size - 1; ++i)
            temp[i] = books[i];
        delete[] books; // delete insufficient array
        // create the new books array with double the previous capacity
        books = new Book[capacity];
        for(int i = 0; i < size - 1; ++i)
            books[i] = temp[i];
        delete[] temp; // delete temporary array
    }
    books[size++] = book;
}

void BookstoreManager::listSize()
{
    cout << "Number of Books in the Bookstore: "<< size << endl;
    cout << capacity << endl;
}