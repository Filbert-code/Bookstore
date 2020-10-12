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
        Book(int isbn): isbn(isbn) { title = "title"; authors = "authors"; publisher = "pub";}
        Book(string title, int isbn, string authors, string publisher):
        title(title), isbn(isbn), authors(authors), publisher(publisher) {}
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