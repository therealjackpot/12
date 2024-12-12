
#include<iostream>
#include<string>
using namespace std;
struct student
{
	int roll;
	string name;
	float sgpa;
};
void bubble_sort(student students[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(students[j].roll>students[j+1].roll)
			{
				student temp=students[j];
				students[j]=students[j+1];
				students[j+1]=temp;
			}
		}
	}
}
void display(student students[],int n)
{
	cout<<"roll_no\t\t\t"<<"name\t\t"<<"SGPA\t\t\t"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<students[i].roll<<"\t\t\t"<<students[i].name<<"\t\t"<<students[i].sgpa<<endl;
	}
}

int main()
{
	int n=3;
	student students[]{
	{39,"alice",6.5},
	{1,"bob",9.9},
	{35,"abc",4.5},
	};
	bubble_sort(students,n);
	display(students,n);
	
	
}