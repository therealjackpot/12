
#include<iostream>
#include<string>
using namespace std;
struct student
{
	int roll;
	string name;
	float sgpa;
};
void display(student students[],int n)
{
	cout<<"Name\t\t"<<"roll_no\t\t"<<"SGPA"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<students[i].name<<"\t\t"<<students[i].roll<<"\t\t"<<students[i].sgpa<<endl;
	}
}
void insertion(student students[],int n)
{
	for(int i=0;i<n;i++)
	{
		student key=students[i];
		int j=i-1;
		while(j>=0 && students[j].name>key.name)
		{
			students[j+1]=students[j];
			j=j-1;
		}
		students[j+1]=key;
	}
}
int main()
{	int n=3;
	student students[]=
	{
		{39,"rane",9.7},
		{12,"anil",9.9},
		{63,"amol",10.00},
	};
	insertion(students,n);
	display(students,n);
	
	
}