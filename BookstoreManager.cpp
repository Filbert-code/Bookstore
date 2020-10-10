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
    if(size + 1>= capacity)
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
    // find the index where the Book should be inserted
    for(int i = 0; i < size; ++i)
    {
        if(book.getIsbn() < books[i].getIsbn())
        {
            for(int k = i; k < size; k++)
            {
                books[i + 1] = books[i];
            }
            books[i] = book;
        }
    }
    if(size == 0)
    {
        books[0] = book;
    }
    size++;
}

void BookstoreManager::print()
{
    for(int i = 0; i < size; ++i)
        cout << books[i];
}

void BookstoreManager::remove(Book &book)
{
    for(int i = 0; i < size; ++i)
    {
        if(books[i].getIsbn() == book.getIsbn())
        {
            for(int k = size - 1; k > i; --k)
            {
                books[k - 1] = books[k];
                --size;
            }
            break;
        }
        cout << "Not Found" << endl;
    }
}

/*
void BookstoreManager::removePublisher(string &pub)
{
    for
}
*/