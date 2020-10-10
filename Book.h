#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <fstream>

using namespace std;

class Book
{
    private:
        string title;
        string authors;
        string publisher;
        int isbn;

    public:
        Book() {}
        Book(string title, int isbn, string authors, string publisher):
        title(title), isbn(isbn), authors(authors), publisher(publisher) {}
        friend ostream &operator<<(ostream &output, Book &b)
        {
            output << b.title + '\n' << b.isbn << endl;
            output << b.authors + '\n' << b.publisher + '\n' << endl;
            return output;
        }
        
        // getters 
        string getTitle() { return title; }
        string getAuthors() { return authors; } 
        string GetPublisher() { return publisher; }
        int GetIsbn() { return isbn; }
};

#endif