#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int empId;
    double salary;

public:
    Employee() {
        empId = 0;
        salary = 0.0;
        name = "Unknown";
    }

    virtual void setDetails() {
        cout << "Enter name, empId, and salary: ";
        cin >> name >> empId >> salary;
    }

    void display() {
        cout << "\nName: " << name
             << "\nId: " << empId
             << "\nSalary: " << salary;
    }

    virtual double monpay() {
        return salary;
    }
};

class Professor : public Employee {
public:
    double monpay() override {
        return salary + salary * 0.1; 
    }
};

// Derived class: Admin
class Admin : public Employee {
public:
    double monpay() override {
        return salary + salary * 0.05;
    }
};

class Janitor : public Employee {
    int workHour;

public:
    void setDetails() override {
        Employee::setDetails();
        cout << "Enter work hours: ";
        cin >> workHour;
    }

    double monpay() override {
        return workHour * 500; 
    }
};

int main() {
    Employee *e;
    Professor p;
    Admin a;
    Janitor j;

    // For Professor
    cout << "For Professor:\n";
    e = &p;
    e->setDetails();
    e->display();
    cout << "\nMonthly Pay: " << e->monpay() << endl;

    // For Admin
    cout << "\nFor Admin:\n";
    e = &a;
    e->setDetails();
    e->display();
    cout << "\nMonthly Pay: " << e->monpay() << endl;

    // For Janitor
    cout << "\nFor Janitor:\n";
    e = &j;
    e->setDetails();
    e->display();
    cout << "\nMonthly Pay: " << e->monpay() << endl;

    return 0;
}
