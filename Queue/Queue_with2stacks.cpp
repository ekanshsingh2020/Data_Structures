#include <bits/stdc++.h>
using namespace std;

class stack_arr
{
public:
    int size;
    int top;
    int *s;
} s1, s2;

void push(stack_arr *st, int num)
{
    if (st->top == st->size - 1)
        cout << "Overflow";
    else
    {
        st->top++;
        st->s[st->top] = num;
    }
}

int pop(stack_arr *st)
{
    int x = -1;
    if (st->top == -1)
        cout << "Underflow";
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(stack_arr s)
{
    if (s.top == -1)
        return 1;
    return 0;
}

void enqueue(int x)
{
    push(&s1, x);
}
int dequeue()
{
    int x = -1;
    if (isEmpty(s2))
    {
        if (isEmpty(s1))
        {
            cout << "Empty";
        }
        else
        {
            while (!isEmpty(s1))
            {
                push(&s2, pop(&s1));
            }
        }
    }
    return pop(&s2);
}

void display()
{
    if (isEmpty(s2) && isEmpty(s1))
        cout << "Empty";
    if (!isEmpty(s2))
    {
        int p = s2.top;
        while (p != -1)
        {
            cout << s2.s[p] << " ";
            p--;
        }
    }
    if (!isEmpty(s1))
    {
        int p = 0;
        while (p <= s1.top)
        {
            cout << s1.s[p] << " ";
            p++;
        }
    }
}

int main()
{
    cin >> s1.size;
    cin >> s2.size;
    s1.s = new int[s1.size];
    s2.s = new int[s2.size];
    s1.top = s2.top = -1;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    display();
    return 0;
}