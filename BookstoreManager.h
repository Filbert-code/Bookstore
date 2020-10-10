#ifndef BOOKSTOREMANAGER_H
#define BOOKSTOREMANAGER_H
#include "Book.h"

using namespace std;

class BookstoreManager
{
    private:
        Book *books;
        int size;
        int capacity;

    public: 
        BookstoreManager();
        bool isEmpty();
        bool isFull();
        void listSize();
        void print();
        void insert(Book &book);
        void remove(Book &book);
        void removePublisher(string &pub);
        void search(Book &book);
};

#endif