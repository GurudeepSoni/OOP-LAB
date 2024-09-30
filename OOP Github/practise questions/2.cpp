#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    Book(string bookTitle, string bookAuthor) 
        : title(bookTitle), author(bookAuthor) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << "\n";
    }
};

class Library {
private:
    Book* books[10];  // Fixed size array
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < 10) {
            books[bookCount++] = new Book(book);
        } else {
            cout << "Library is full.\n";
        }
    }

    void displayBooks() const {
        for (int i = 0; i < bookCount; ++i) {
            books[i]->display();
        }
    }

    ~Library() {
        for (int i = 0; i < bookCount; ++i) {
            delete books[i];
        }
    }
};

int main() {
    Library library;
    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));
    
    library.displayBooks();
    return 0;
}
