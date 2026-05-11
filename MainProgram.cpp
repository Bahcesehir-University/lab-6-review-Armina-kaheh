// ============================================================
// Lab W7: C++ OOP Review - Classes, Encapsulation, Strings,
//         Copy Constructors, Operator Overloading
// Course: Object-Oriented Programming
// Duration: 40 minutes
// ============================================================
// SINGLE FILE IMPLEMENTATION - No header files allowed
// ============================================================

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// ================================
// CLASS DEFINITIONS
// ================================

// -----------------------------------------------------------
// Class: Student
// Represents a university student with name, ID, and GPA.
// -----------------------------------------------------------
class Student {
private:
    string name;
    int id;
    double gpa;

public:
    // ----- Task 1: Constructors & Destructor -----

    // Default constructor
    Student() {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }

    // Parameterized constructor
    Student(string n, int i, double g) {
        name = n;
        id = i;
        gpa = g;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        id = other.id;
        gpa = other.gpa;
    }

    // Destructor
    ~Student() {
        cout << "Student " << name << " destroyed" << endl;
    }

    // ----- Task 2: Getters (Encapsulation) -----

    // Getter for name
    string getName() const {
        return name;
    }

    // Getter for id
    int getId() const {
        return id;
    }

    // Getter for gpa
    double getGpa() const {
        return gpa;
    }

    // ----- Task 3: Setters with Validation -----

    // Setter for name
    void setName(string n) {
        if (!n.empty()) {
            name = n;
        }
    }

    // Setter for GPA
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }

    // ----- Task 4: String Operation -----

    // Return the name in uppercase
    string getFormattedName() const {
        string upperName = name;

        for (int i = 0; i < upperName.length(); i++) {
            upperName[i] = toupper(upperName[i]);
        }

        return upperName;
    }

    // ----- Task 5: Operator Overloading -----

    // Equality operator
    bool operator==(const Student& other) const {
        return id == other.id;
    }

    // Less-than operator
    bool operator<(const Student& other) const {
        return gpa < other.gpa;
    }

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << "Student(" << s.name
           << ", ID: " << s.id
           << ", GPA: " << s.gpa << ")";
        return os;
    }
};

// ================================
// STANDALONE FUNCTION
// ================================

// Version 1: Compare two students
Student findBestStudent(const Student& a, const Student& b) {
    if (a.getGpa() > b.getGpa()) {
        return a;
    }
    return b;
}

// Version 2: Compare array of students
Student findBestStudent(Student arr[], int size) {
    Student best = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i].getGpa() > best.getGpa()) {
            best = arr[i];
        }
    }

    return best;
}

// ================================
// MAIN FUNCTION
// ================================
int main() {
    // --- Demo: Default Constructor ---
    Student s1;
    cout << "Default: " << s1 << endl;

    // --- Demo: Parameterized Constructor ---
    Student s2("Ali", 101, 3.5);
    Student s3("Ayse", 102, 3.8);
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    // --- Demo: Copy Constructor ---
    Student s4(s2);
    cout << "Copy of s2: " << s4 << endl;

    // --- Demo: Encapsulation (Getters) ---
    cout << "s3 name: " << s3.getName() << endl;
    cout << "s3 GPA: " << s3.getGpa() << endl;

    // --- Demo: Setter Validation ---
    s2.setGpa(5.0);  // Invalid, should not change
    cout << "s2 after invalid setGpa(5.0): " << s2 << endl;

    s2.setGpa(3.9);  // Valid
    cout << "s2 after valid setGpa(3.9): " << s2 << endl;

    // --- Demo: String Operation ---
    cout << "Formatted: " << s3.getFormattedName() << endl;

    // --- Demo: Operator Overloading ---
    cout << "s2 == s4? " << (s2 == s4 ? "Yes" : "No") << endl;
    cout << "s2 < s3? " << (s2 < s3 ? "Yes" : "No") << endl;

    // --- Demo: Function Overloading ---
    Student best2 = findBestStudent(s2, s3);
    cout << "Best of two: " << best2 << endl;

    Student roster[] = {s1, s2, s3, s4};
    Student bestAll = findBestStudent(roster, 4);
    cout << "Best of all: " << bestAll << endl;

    return 0;
}
