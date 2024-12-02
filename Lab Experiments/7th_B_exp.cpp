#include <iostream>
#include <string>
using namespace std;

class Books {
private:
    static int countBook;
    string bookName;
    string bookId;

public:
    Books() {
        countBook++;
        bookId = "PCE" + to_string(countBook);
    }

    Books(string bookName) {
        countBook++;
        this->bookName = bookName;
        bookId = "PCE" + to_string(countBook);
    }

    ~Books() {
        cout<<"Destructor";
    }

    void display() const {
        cout << "Book Name: " << bookName << endl;
        cout << "Book ID: " << bookId << endl;
    }

    void noofbooksS(){
        cout<<"no of books are : "<<countBook<<endl;
    } 
};

int Books::countBook = 0;

int main() {
    Books b1("Thomas");
    b1.display();
    cout << endl;

    Books b2("Endgame");
    b2.display();
    cout << endl;

    Books b3("Secret war");
    b3.display();
    cout << endl;

    b1.noofbooksS();
    return 0;
}

