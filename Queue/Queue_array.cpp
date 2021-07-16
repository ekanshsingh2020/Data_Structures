#include<bits/stdc++.h>
using namespace std;
//FIFO
class queue_arr{
    public:
    int size,front,rear;
    int *Q;

};

void enqueue(queue_arr *q,int x)
{
    if(q->rear==q->size-1)
    {
        cout<<"Full";
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

void display(queue_arr q)
{
    for (int i = q.front+1; i <=q.rear; i++)
    {
        cout<<q.Q[i]<<" ";
    }
    
}
int dequeue(queue_arr *q)
{
    int x=-1;
    if(q->rear==q->front)
    cout<<"Empty";
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

//Drawback:Non reusability of empty memory spaces



int main()
{
    queue_arr q;
    cin>>q.size;
    q.Q=new int[q.size];
    q.rear=q.front=-1;

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    dequeue(&q);
    display(q);
    return 0;
}