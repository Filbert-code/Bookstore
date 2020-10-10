#include "BookstoreManager.h"
#include <iostream>

BookstoreManager::BookstoreManager()
{
    size = 0;
    capacity = 5;
    books = new Book[capacity];
}

bool BookstoreManager::isEmpty()
{
    if(size == 0)
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return size == 0;
}

bool BookstoreManager::isFull()
{
    if(size == capacity)
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return size == capacity;
}

void BookstoreManager::listSize()
{
    cout << "Number of Books in the Bookstore: "<< size << endl;
    cout << capacity << endl;
}

void BookstoreManager::insert(Book &book)
{
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
    books[size++] = book;
}

void BookstoreManager::print()
{
    for(int i = 0; i < size; ++i)
        cout << books[i];
}