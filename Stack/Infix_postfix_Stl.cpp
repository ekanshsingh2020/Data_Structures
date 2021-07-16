#include <bits/stdc++.h>
using namespace std;

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

char *convert(string infix)
{
    stack<char> st;
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
            if (pre(infix[i]) > pre(st.top()))
            {
                st.push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = st.top();
                st.pop();
                j++;
            }
        }
    }
    while (st.empty())
    {
        postfix[j]=st.top();
        j++;
    }
    postfix[j] = '\0';
    
    return postfix;
}
int main()
{

    string str = {"a+b*c-d/e"};
    cout<<convert(str);
    return 0;
}