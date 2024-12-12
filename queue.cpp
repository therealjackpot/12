#include<iostream>
using namespace std;
int queue[5];
int front=-1;
int rear=-1;
int n=5;
void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
        cout<<"Overflow";
        return;
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Underflow";
        return;
    }
    else if(front==rear)
    {
        cout<<"dequeue elemet="<<queue[front];
        front=rear=-1;
    }
    else
    {
        cout<<"Dequeue element"<<queue[front];
        front=(front+1)%n;
    }
}
void display()
{   int i=front;
    if(front==-1 && rear==-1)
    {
        cout<<"Underflow";
        return;
    }
    else
    {
        cout<<"Elements in queue\n";
        while(i!=rear)
        {
            cout<<queue[i];
            i=(i+1)%n;
        }
        cout<<queue[rear];
        
    }
}
int main()
{
     int ch, val;
    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Display\n";
    cout << "4) Exit\n";
    do {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Input for Insertion: ";
            cin >> val;
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Incorrect choice!\n";
        }
    } while (ch != 4);
    return 0;

}