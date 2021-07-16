#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *rchild;
    node *lchild;
};

void insert(node *root, int key)
{
    node *t = NULL, *p;
    while (root)
    {
        t = root;
        if (key == root->data)
            return;
        else if (key < root->data)
        {
            root = root->lchild;
        }
        else
            root = root->rchild;
    }
    p = new node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (p->data < t->data)
        t->lchild = p;
    else
        t->rchild = p;
}

node *root;

void create()
{
    cout << "Enter the root value ";
    root = new node;
    root->lchild = root->rchild = NULL;
    cin >> root->data;
    int x = 0;
    while (1)
    {
        cout << "Enter the value to be inserted ";
        cin >> x;
        if (x == -1)
            break;
        insert(root, x);
    }
}

int height(node *root)
{
    int x, y;
    if (root)
    {
        x = height(root->lchild);
        y = height(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return -1;
}

node *InPre(node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

node *InSucc(node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
node *del(node *p, int key)
{
    if (p == NULL)

        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if (key < p->data)
        p->lchild = del(p->lchild, key);
    else if (key > p->data)

        p->rchild = del(p->rchild, key);
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            node *q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = del(p->lchild, q->data);
        }
        else
        {
            node *q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = del(p->rchild, q->data);
        }
    }
        return p;
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
    inorder(root);int key;
    cout<<"What do u wanna delete";
    cin>>key;
    del(root,key);cout<<endl;
    inorder(root);
    return 0;
}
