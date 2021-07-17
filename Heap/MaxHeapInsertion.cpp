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

    return 0;
}