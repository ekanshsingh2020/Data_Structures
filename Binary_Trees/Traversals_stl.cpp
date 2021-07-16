#include<bits/stdc++.h>
using namespace std;

void create()
{
    list<int> l;
    int x;
    queue<int*>q;
    cout<<"Enter the root value ";
    cin>>x;
    l.push_back(x);
    q.push(&l.front());

    while (!q.empty())
    {
        int *p=q.front();
        q.pop();
        cout<<"Enter the left child of "<<*p<<" ";
        cin>>x;
        if(x!=-1)
        {
            
        }

    }
    
}


int main()
{
    
    return 0;
}