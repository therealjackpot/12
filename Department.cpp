#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addStudent() {
    string roll, name, division, address;
    cout << "Enter roll number: ";
    cin >> roll;
    cin.ignore(); // Ignore the newline
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter division: ";
    getline(cin, division);
    cout << "Enter address: ";
    getline(cin, address);

    ofstream outFile("student_database.txt", ios::app);
    outFile << roll << "," << name << "," << division << "," << address << endl;
    outFile.close();
    cout << "Student added successfully!" << endl;
}

void deleteStudent() {
    string roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    ifstream inFile("student_database.txt");
    ofstream outFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.substr(0, line.find(',')) != roll) {
            outFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("student_database.txt");
    rename("temp.txt", "student_database.txt");

    if (found) {
        cout << "Student record deleted!" << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

void displayStudent() {
    string roll;
    cout << "Enter roll number to display: ";
    cin >> roll;

    ifstream inFile("student_database.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.substr(0, line.find(',')) == roll) {
            cout << "Record found: " << line << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }
    inFile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. Delete Student\n3. Display Student\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            deleteStudent();
        } else if (choice == 3) {
            displayStudent();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}