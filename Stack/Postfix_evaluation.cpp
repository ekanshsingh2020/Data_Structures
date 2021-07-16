#include <bits/stdc++.h>
using namespace std;

class stack_arr
{
public:
    int size;
    int top;
    int *s; //Cuz here integers have to be stored in stack
};
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
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

int pop(stack_arr *st)
{
    int x;
    if (st->top == -1)
        cout << "Underflow";
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}


int eval(string postfix)
{
    stack_arr st;
    st.size = postfix.length();
    st.top = -1;
    st.s = new int[st.size];

    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(&st, postfix[i] - '0'); //Cuz char is passed, so to get proper ascii code
        }
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(&st, r);
                break;
            case '-':
                r = x1 - x2;
                push(&st, r);
                break;
            case '*':
                r = x1 * x2;
                push(&st, r);
                break;
            case '/':
                r = x1 / x2;
                push(&st, r);
                break;

            default:
                break;
            }
        }
    }
    return pop(&st);
}

int main()
{
    string str;
    cin >> str;
    cout << eval(str);
    return 0;
}