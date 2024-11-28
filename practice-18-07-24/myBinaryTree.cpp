#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left = NULL;
    Node *right = NULL;
};

class Tree
{
public:
    Node *root = new Node;

    Tree()
    {
        root = NULL;
    }

    void addLeft(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (root == NULL)
            root = newNode;
        else
            {
                Node *temp = new Node;
                
                while(temp->left != NULL && temp->right != NULL)
                {
                    
                }
            }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *a = new Node;
    Tree *tr = new Tree;
    tr->root = a;
    tr->root->value = 1;

    Node *b = new Node;
    Node *c = new Node;
    b->value = 2;
    c->value = 3;

    tr->root->left = b;
    tr->root->right = c;

    cout << tr->root->right->value;

    return 0;
}