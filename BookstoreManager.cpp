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
    // refill the books array with the updated array values
    for(int k = 0; k < size; ++k)
    {
        books[k] = temp[k];
    }
    delete[] temp; // get rid of the temporary array
}