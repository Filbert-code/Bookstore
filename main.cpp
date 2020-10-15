// Author: Alex Filbert
// Date: 10/10/2020
// Course: CS 300B
// Assignment: Homework 2
#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main()
{
    // creating an instance of the BookstoreManager class
    BookstoreManager bookstoreManager;

    // prints true if the bookstore is empty
    bookstoreManager.isEmpty();

    // insert 4 books
    string title, authors, publisher;
    int isbn;
    for(int i=0;i<4;i++)
    {
        cout << "Enter book title: ";
        // using getline instead of cin for multi-word inputs
        getline(cin, title); 
        cout<<"Enter authors: ";
        getline(cin, authors);
        cout<<"Enter isbn: ";
        cin>>isbn;
        cin.ignore(256, '\n'); // ignore any characters that are still in cin
        cout<<"Enter publisher: ";
        getline(cin, publisher);
        Book aBook(title, isbn, authors, publisher); // create Book object
        bookstoreManager.insert(aBook); // insert into dynamic array
        cout<<endl;
    }
    // checks if the bookstore is full
    bookstoreManager.isFull();

    // print bookstore
    bookstoreManager.print();

    // search for books
    cout << "Searching..." << endl;
    cout << "ISBN: ";
    cin>>isbn;
    cin.ignore(256, '\n');
    Book b2(isbn);
    bookstoreManager.search(b2);

    // remove a book
    cout << "Removing..." << endl;
    cout << "ISBN: ";
    cin >> isbn;
    cin.ignore(256, '\n');
    Book b1(isbn);
    bookstoreManager.remove(b1);

    // print bookstore
    bookstoreManager.print();

    // remove books from a particular publisher
    cout << "Removing publisher" << endl;
    cout << "Publisher: ";
    string pub;
    getline(cin, pub);
    cout << endl;
    bookstoreManager.removePublisher(pub);

    // print bookstore
    bookstoreManager.print();

    // prints the number of books
    bookstoreManager.listSize();
}