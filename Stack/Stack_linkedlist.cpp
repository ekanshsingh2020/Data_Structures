#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
/*Either make the head pointer globally so that every one can access that or pass pointer to pointer
in the functions so that they can modify the pointers as well*/
void push(node **top, int num)
{
    node *t = new node;
    if (t == NULL)
        cout << "Overflow";
    else
    {
        t->data = num;
        t->next = *top;
        *top = t;
    }
}

void display(node **top)
{
    node *t = *top;
    if (*top == NULL)
        cout << "Empty";
    else
    {
        while (t)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }
}

void pop(node **top)
{
    if (*top == NULL)
        cout << "Underflow";
    else
    {
        node *t = *top;
        *top = (*top)->next;
        delete t;
    }
}

int main()
{
    node *top = NULL;
    push(&top, 10);
    push(&top, 30);
    push(&top, 50);
    pop(&top);
    display(&top);
    return 0;
}