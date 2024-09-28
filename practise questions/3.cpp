#include <iostream>

using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;

public:
    Contact(string n, string p) : name(n), phoneNumber(p) {}

    void display() const {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << "\n";
    }
};

class ContactManager {
private:
    Contact* contacts[10];  // Fixed size array
    int contactCount;

public:
    ContactManager() : contactCount(0) {}

    void addContact(const Contact& contact) {
        if (contactCount < 10) {
            contacts[contactCount++] = new Contact(contact);
        } else {
            cout << "Contact list is full.\n";
        }
    }

    void displayContacts() const {
        for (int i = 0; i < contactCount; ++i) {
            contacts[i]->display();
        }
    }

    ~ContactManager() {
        for (int i = 0; i < contactCount; ++i) {
            delete contacts[i];
        }
    }
};

int main() {
    ContactManager manager;
    manager.addContact(Contact("Alice", "123-456-7890"));
    manager.addContact(Contact("Bob", "987-654-3210"));

    manager.displayContacts();
    return 0;
}
