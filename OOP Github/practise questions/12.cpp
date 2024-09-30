#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    // Constructor declaration
    Complex(void); 

    // Method to print the complex number
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

// Default constructor definition
Complex::Complex(void) // This is a default constructor as it takes no parameters
{
    a = 10;
    b = 0;
    // cout << "Hello world"; // You can uncomment this if you want to see a message when the constructor is called
}

int main()
{
    // Creating an object of Complex
    Complex num;

    // Print the initialized complex number
    num.printNumber();

    return 0;
}
