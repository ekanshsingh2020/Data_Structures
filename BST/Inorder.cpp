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