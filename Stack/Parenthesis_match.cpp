#include <bits/stdc++.h>
using namespace std;

class stack_arr
{
public:
    int size;
    int top;
    char *s;
};

void push(stack_arr *st, char c)
{
    st->top++;
    st->s[st->top] = c;
}

void pop(stack_arr *st)
{
    st->top--;
}

int isMatch(string str)
{
    stack_arr st;
    st.size = str.length();
    st.top = -1;
    st.s = new char[st.size];

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            push(&st, '(');
        else if (str[i] == ')')
        {
            if (st.top == -1)
                return 0;
            pop(&st);
        }
    }
    if (st.top == -1)
        return 1;
    return 0;
}
int main()
{
    string str;
    cin >> str;
    cout << isMatch(str);
    return 0;
}