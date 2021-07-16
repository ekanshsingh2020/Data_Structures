#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
} * top;

void display()
{
    node *f = top;
    do
    {
        cout << f->data << " ";
        f = f->next;
    } while (f != top);
}

void insert(int pos, int num)
{
    node *t = new node();
    if (pos == 0)
    {
        t->data = num;
        if (top == NULL)
        {
            t->next = t;
        }
        if (top != NULL)
        {
            t->next = top;
            node *p = top;
            while (p->next)
            {
                p = p->next;
            }
            p->next = t;
        }
        top = t;
    }
    else
    {
        node *p = top;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->data = num;
        t->next = p->next;
        p->next = t;
    }
}

void del(int pos) //pos must be index from 0
{
    if (pos == 0)
    {
        node *p = top;
        while (p->next)
        {
            p = p->next;
        }
        node*t=top;
        top=top->next;
        p->next=t->next;
        delete t;
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

int main()
{
    top = NULL;
    return 0;
}
