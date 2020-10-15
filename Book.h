// Author: Alex Filbert
// Date: 10/10/2020
// Course: CS 300B
// Assignment: Homework 2
#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <fstream>

using namespace std;

class Book
{
    private:
        // private member variables
        string title;
        string authors;
        string publisher;
        int isbn;

    public:
        Book() {} // default constructor
        Book(int isbn): isbn(isbn) {} // isbn overloaded constructor
        Book(string title, int isbn, string authors, string publisher): // 4-arg constructor
        title(title), isbn(isbn), authors(authors), publisher(publisher) {}
        // overloading the << operator to allow printing the private variables to console
        friend ostream &operator<<(ostream &output, Book &b)
        {
            output << b.title + '\n' << b.isbn << endl;
            output << b.authors + '\n' << b.publisher + '\n' << endl;
            return output;
        }
        // getters and setters
        string getTitle() { return title; }
        void setTitle(string nTitle) { title = nTitle; }
        string getAuthors() { return authors; } 
        void setAuthors(string nAuthors) { authors = nAuthors; }
        string getPublisher() { return publisher; }
        void setPublisher(string nPublisher) { publisher = nPublisher; }
        int getIsbn() { return isbn; }
        void setIsbn(int nIsbn) { isbn = nIsbn; }
};

#endif