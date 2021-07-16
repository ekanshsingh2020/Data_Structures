#include <bits/stdc++.h>
using namespace std;

class stack_arr
{
public:
    int size;
    int top;
    char *s;
};

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void push(stack_arr *st, char c)
{
    if (st->top == st->size - 1)
        cout << "Overflow";
    else
    {
        st->top++;
        st->s[st->top] = c;
    }
}

char pop(stack_arr *st)
{
    char x;
    if (st->top == -1)
        cout << "Underflow";
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

char *convert(string infix)
{
    stack_arr st;
    st.size = infix.length();
    st.top = -1;
    st.s = new char[st.size];
    char *postfix = new char[infix.length() + 1];

    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (pre(infix[i]) > pre(st.s[st.top]))
            {
                push(&st, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(&st);
                j++;
            }
        }
    }
    while ((st.top) != -1)
    {
        postfix[j] = pop(&st);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    string str = {"a+b*c-d/e"};

    cout << convert(str);

    return 0;
}