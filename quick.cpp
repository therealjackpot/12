#include <iostream>
#include <string>
using namespace std;
struct Student {
    int rollNo;
    string name;
    float sgpa;
};
int partition(Student a[], int lb, int ub) {
    float pivot = a[lb].sgpa; 
    int start = lb;
    int end = ub;

    while (start < end){
        while (a[start].sgpa>= pivot) {
            start++;
        }
        while (a[end].sgpa<pivot) {
            end--;
        }
        if (start < end) {
            Student temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
    Student temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}
void quick(Student a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quick(a, lb, loc - 1);
        quick(a, loc + 1, ub);
    }
}
void printTop10(Student a[], int n) {
    for (int i=0; i<n; i++) {
        cout << "Roll No: " << a[i].rollNo
             << ", Name: " << a[i].name
             << ", SGPA: " << a[i].sgpa << endl;
    }
}
int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student students[n];
    for (int i = 0; i <n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> students[i].rollNo;
        cin.ignore();
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }
    quick(students, 0, n- 1);
    cout << "\nTop 10 Toppers (Based on SGPA):\n";
    printTop10(students,n);

    return 0;
}