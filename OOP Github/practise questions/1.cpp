#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int grades[10];
    int gradeCount;

public:
    Student(string studentName) : name(studentName), gradeCount(0) {}

    void addGrade(int grade) {
        if (gradeCount < 10) {
            grades[gradeCount++] = grade;
        } else {
            cout << "Maximum grades reached.\n";
        }
    }

    double calculateAverage() const {
        if (gradeCount == 0) return 0;
        int sum = 0;
        for (int i = 0; i < gradeCount; ++i) {
            sum += grades[i];
        }
        return static_cast<double>(sum) / gradeCount;
    }

    void displayInfo() const {
        cout << "Student: " << name << ", Average Grade: " << calculateAverage() << "\n";
    }
};

int main() {
    Student student("John");
    student.addGrade(85);
    student.addGrade(90);
    student.addGrade(78);
    student.displayInfo();
    return 0;
}
