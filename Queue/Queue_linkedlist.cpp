#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
} * front, *rear;

void enqueue(int x)
{
    node *t = new node();
    if (t == NULL)
        cout << "Full";
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    if (front == NULL)
        cout << "Empty";
    else
    {
        node *t = front;
        front = front->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display()
{
    node*t=front;
    while (t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    
}


int main()
{
    front = rear = NULL;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}