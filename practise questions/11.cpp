#include <iostream>
using namespace std;

class Y; // Forward declaration of class Y

class X {
    int data;
public:
    void setValue(int value) {
        data = value;
    }
    friend void add(X, Y); // Friend function declaration
};

class Y {
    int num;
public:
    void setValue(int value) {
        num = value;
    }
    friend void add(X, Y); // Friend function declaration
};

// Function to add data from X and Y
void add(X o1, Y o2) {
    cout << "Summing data of X and Y objects gives me " << o1.data + o2.num << endl;
}

// Class c1
class c1 {
    int val1;
    friend void exchange(c1&, class c2&); // Forward declaration of c2
public:
    void indata(int a) {
        val1 = a;
    }

    void display(void) {
        cout << val1 << endl;
    }
};

// Class c2
class c2 {
    int val2;
    friend void exchange(c1&, c2&);
public:
    void indata(int a) {
        val2 = a;
    }

    void display(void) {
        cout << val2 << endl;
    }
};

// Function to exchange values between c1 and c2
void exchange(c1 &x, c2 &y) {
    int tmp = x.val1;
    x.val1 = y.val2;
    y.val2 = tmp;
}

int main() {
    // Create objects of class X and Y
    X oc1;
    Y oc2;

    oc1.setValue(34); // Set value for oc1
    oc2.setValue(67); // Set value for oc2

    // Call the add function to sum values
    add(oc1, oc2);

    // Create objects of class c1 and c2
    c1 obj1;
    c2 obj2;

    obj1.indata(10); // Set value for obj1
    obj2.indata(20); // Set value for obj2

    // Display values before exchange
    cout << "Before exchange:" << endl;
    cout << "c1: ";
    obj1.display();
    cout << "c2: ";
    obj2.display();

    // Exchange values between obj1 and obj2
    exchange(obj1, obj2);

    // Display values after exchange
    cout << "After exchange:" << endl;
    cout << "c1: ";
    obj1.display();
    cout << "c2: ";
    obj2.display();

    return 0;
}
