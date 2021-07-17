#include <bits/stdc++.h>
using namespace std;

void heapify(int A[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        int j = 2 * i;
        while (j < n - 1)
        {
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }
            if (A[i] < A[j])
            {
                int temp = A[j];
                A[j] = A[i];
                A[i] = temp;
                i = j;
                j = 2 * i;
            }
            else
                break;
        }
    }
}

int main()
{
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int i;
    for (i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    heapify(A, 7);
    for (i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
