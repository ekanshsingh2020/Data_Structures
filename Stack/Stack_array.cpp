#include <bits/stdc++.h>
using namespace std;

class stack_arr
{
public:
    int size;
    int top;
    int *s;
};

int peek(stack_arr st, int pos)
// Here the postion is from the top of stack and not with 0 indexing
//Call by value will work too as we dont modify here
{
    int x = -1;
    if (st.top - pos + 1 < 0)
        cout << "Invalid";
    else
        x = st.s[st.top - pos + 1];

    return x;
}

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

void pop(stack_arr *st)
// int pop(stack_arr *st)   //If want to return what was popped
{
    int x = -1;
    if (st->top == -1)
        cout << "Underflow";
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    // return x;
}

void display(stack_arr *st)
{
    for (int i = 0; i <= st->top; i++)
    {
        cout << st->s[i] << " ";
    }
}

int main()
{
    stack_arr st;
    cin >> st.size;
    st.top = -1;
    st.s = new int[st.size];
    push(&st, 20);
    push(&st, 40);
    push(&st, 60);
    pop(&st);
    display(&st);
    return 0;
}

