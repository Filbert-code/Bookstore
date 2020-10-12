#include <iostream>
#include "Book.h"
#include "BookstoreManager.h"

using namespace std;

int main()
{
    BookstoreManager bsm;

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
        bsm.insert(aBook);
        cout<<endl;
    }
    bsm.listSize();
    bsm.print();

/*
    string pub;
    cout << "Publisher to remove: ";
    cin >> pub;
    bsm.removePublisher(pub);

    bsm.listSize();
    bsm.print();
*/

/*
    ifstream file("testdata.txt");

    string title, authors, publisher;
    string isbn;
    string line;
    for(int i = 0; i < 4; ++i)
    {
        getline(file, title);
        getline(file, authors);
        getline(file, isbn);
        getline(file, publisher);
        int iIsbn = stoi(isbn);
        Book aBook(title, iIsbn, authors, publisher);
        //bookstoreManager.insert(aBook);
    }
*/
}