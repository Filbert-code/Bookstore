#include <iostream>
#include "Book.h"

using namespace std;

int main()
{

    Book arr[4];

    string title, authors, publisher;
    int isbn;
    for(int i=0;i<4;i++)
    {
        cout << "Enter book title: ";
        getline(cin, title);
        cout<<"Enter authors: ";
        getline(cin, authors);
        cout<<"Enter isbn: ";
        cin>>isbn;
        cin.ignore(256, '\n'); // ignore any characters that are still in cin
        cout<<"Enter publisher: ";
        getline(cin, publisher);
        Book aBook(title, isbn, authors, publisher);
        arr[i] = aBook;
        //bookstoreManager.insert(aBook);
        cout<<endl;
    }

    for(int i = 0; i < 4; ++i)
    {
        cout << arr[i];
    }
}