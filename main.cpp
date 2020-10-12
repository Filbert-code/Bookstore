#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main()
{
    BookstoreManager bsm;

    string title, authors, publisher;
    int isbn;
    for(int i=0;i<3;i++)
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
        bsm.insert(aBook);
        cout<<endl;
    }
    bsm.listSize();
    bsm.print();

    cout << "===========\n";

    cout << "Searching...\nISBN:";
    int val;
    cin >> val;
    Book b(val);
    bsm.search(b);



    //bsm.listSize();
    //bsm.print();
}