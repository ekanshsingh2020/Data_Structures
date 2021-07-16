#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *rchild;
    node *lchild;
};

class queue_arr
{
public:
    int size, front, rear;
    node **Q;
};

int isEmpty(queue_arr q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}

void enqueue(queue_arr *q, node *x)
{
    if (q->rear == q->size - 1)
    {
        cout << "Full";
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

node *dequeue(queue_arr *q)
{
    node *x = 0;
    if (q->rear == q->front)
        cout << "Empty";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

node *root=NULL;

void create()
{
    node *p, *t;
    int x;
    queue_arr q;
    q.front = q.rear = -1;
    q.size = 100;
    q.Q = new node *[q.size];
    cout << "Enter the root value ";
    cin >> x;
    root = new node();
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);

        cout<<"Enter the left child of "<<p->data<<" ";
        cin >> x;
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout << "Enter the right child of " << p->data<<" ";
        cin >> x;
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}


void inorder(node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}

int main()
{
    create();
    inorder(root);
    
    return 0;
}