#include <bits/stdc++.h>
using namespace std;
class circular_queue_arr
{
public:
    int size, front, rear;
    int *Q;
};

void enqueue(circular_queue_arr *q, int x)
{
    if ((q->rear+1)%(q->size)==q->front)
    {
        cout << "Full";
    }
    else
    {
        q->rear=(q->rear+1)%(q->size);
        q->Q[q->rear] = x;
    }
}

void display(circular_queue_arr q)
{
    int i=(q.front+1)%(q.size);
    while (!(i==(q.rear+1)%(q.size)))
    {
        cout<<q.Q[i]<<" ";
        i=(i+1)%(q.size);
    }
    
}
int dequeue(circular_queue_arr *q)
{
    int x = -1;
    if (q->rear == q->front)
        cout << "Empty";
    else
    {
        q->front=(q->front+1)%(q->size);
        x = q->Q[q->front];
    }
    return x;
}
int main()
{
    circular_queue_arr q;
    cin >> q.size;
    q.Q = new int[q.size];
    q.rear = q.front = 0;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    dequeue(&q);
    display(q);
    return 0;
}