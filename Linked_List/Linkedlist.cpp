#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
} * top;

void insert(int pos, int num)
{
    node *temp = new node;
    if (pos == 0)
    {
        temp->data = num;
        temp->next = top;
        top = temp;
    }
    else
    {
        node *p = top;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        temp->data = num;
        p->next = temp;
    }
}

void display()
{
    node *t = top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

void del(int pos)
{
    if (top == NULL)
        cout << "Empty";
    if (pos == 0)
    {
        node *p = top;
        top = top->next;
        int x = p->data;
        delete p;
    }
    else
    {
        node *p, *q;
        p = top;
        q = NULL;
        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        int x = p->data;
        delete p;
    }
}

void reverse()
{
    node *p, *q, *r;
    p = top;
    q = NULL;
    r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    top = q;
}

int main()
{
    
    return 0;
}