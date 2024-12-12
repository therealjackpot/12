

#include<iostream>
#include<string>
using namespace std;
struct student
{
    int roll_no;
    string name;
    float sgpa;
};
int binary_search(student students[],int n,string target)
{
    int lb=0;
    int ub=n-1;
     while (lb <=ub ){
        int mid = (lb +ub) / 2;

        // Compare the name at mid with the target name
        if (students[mid].name == target) {
            return mid;  // Found
        }
        else if (students[mid].name < target) {
            lb= mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }

    return -1;  // Not found
}
void display(student &students)
{
    cout<<"Roll_no="<<students.roll_no<<"\nName="<<students.name<<"\nSGPA="<<students.sgpa;
}

int main()
{
    student students[]={
        {1,"Alice",5.5},{2,"Bob",8.8},{3,"Daniel",6.6},{4,"Elias",7.7}
    };
    string target;
    cout<<"Enter the name of student to be search=";
    cin>>target;
    int n=sizeof(students)/sizeof(students[0]);
    int index=binary_search(students,n,target);
    if(index!=-1)
    {
        cout<<"Student found at index"<<index<<endl;
        display(students[index]);
    }
    
    
    
}