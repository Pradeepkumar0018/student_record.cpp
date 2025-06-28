
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    Student s;
    ofstream out("students.txt", ios::app);
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(s.name, 50);
    cout << "Enter Marks: ";
    cin >> s.marks;
    out.write((char*)&s, sizeof(s));
    out.close();
    cout << "Student record added.\n";
}

void displayStudents() {
    Student s;
    ifstream in("students.txt");
    while (in.read((char*)&s, sizeof(s))) {
        cout << "\nRoll No: " << s.roll;
        cout << "\nName: " << s.name;
        cout << "\nMarks: " << s.marks << "\n";
    }
    in.close();
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. Display Students\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);
    return 0;
}
