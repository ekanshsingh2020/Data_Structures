#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
} * top;

void insert(int pos, int num)
{
    node *t = new node();
    if (pos == 0)
    {
        t->data = num;
        t->prev = NULL;
        t->next = top;
        if (top != NULL)
        {
            top->prev = t;
        }
        top = t;
    }
    else
    {
        t->data = num;
        node *p = top;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = t;
            p->next = t;
        }
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
        if (top != NULL)
            top->prev = NULL;
    }
    else
    {
        node *p = top;
        for (int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        delete p;
    }
}

void reverse()
{

}

int main()
{
    
    return 0;
}
