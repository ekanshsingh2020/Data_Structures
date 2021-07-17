#include <bits/stdc++.h>
using namespace std;

void insert(int a[], int n)
{
    int temp, i = n;
    temp = a[n];
    while (i > 1 && temp > a[i / 2])
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

void del(int a[], int n)
{
    int x, i, j;
    x = a[n];
    i = 1;int p=a[i];
    j = 2 * i;
    a[i] = a[n];

    while (j <=n - 1)
    {
        if (a[j + 1] > a[j])
        {
            j = j + 1;
        }
        if (a[i] < a[j])
        {
            int y = a[i];
            a[i] = a[j];
            a[j] = y;
            i = j;
            j = j * 2;
        }
        else
            break;
    }
    a[n] = p;
}

int main()
{
    int A[] = {0, 10, 20, 30, 40, 25, 5, 35};
    int i;
    for (i = 2; i <= 7; i++)
    {
        insert(A, i);
    }
    for (i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    for ( i = 7; i >=1; i--)
    {
        del(A,i);
    }
    
    for (i = 1; i <= 7; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}