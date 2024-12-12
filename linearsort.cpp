
#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int roll_no;
    string name;
    float sgpa;
};
void linear(Student Students[],int n,float search_sgpa)
{
    count=0;
    for(int i=0;i<n;i++)
    {
        if(Students[i].sgpa==search_sgpa)
        {
            count++;
        }
    }
    if(count>1)
    {  
        cout<<"list of students with SGPA:"<<search_sgpa<<endl;
        for(int i=0;i<n;i++)
        {
            if(Students[i].sgpa==search_sgpa)
            {
                cout<<"\nRoll_no="<<Students[i].roll_no;
                cout<<", name="<<Students[i].name;
                cout<<", sgpa="<<Students[i].sgpa;
           }
        }
    }
    else if(count==1)
    {
        cout<<"only one student have SGPA,"<<search_sgpa<<endl;
    }
    else
    {
        cout<<"No Sgpa found";
    }
    
    
    
}
int main()
{
    int n;
    cout<<"Enter number of students=";
    cin>>n;
    Student Stu[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter details of "<<i+1<<" Student\n";
        cout<<"roll_no=";
        cin>>Stu[i].roll_no;
        cout<<"name=";
        cin.ignore();
        getline(cin,Stu[i].name);
        cout<<"sgpa=";
        cin>>Stu[i].sgpa;
    }
    float search_sgpa;
    cout<<"Enter SGPA to be searched:";
    cin>>search_sgpa;
    linear(Stu,n,search_sgpa);
}