#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

void printLevelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);

    while (que.size() > 0)
    {
        Node *currentNode = que.front();
        if (currentNode == root)
            cout << currentNode->value << " ";
        que.pop();

        if (currentNode->left)
        {
            que.push(currentNode->left);
            cout << currentNode->left->value << " ";
        }
        else
            cout << -1 << " ";
        if (currentNode->right)
        {
            que.push(currentNode->right);
            cout << currentNode->right->value << " ";
        }
        else
            cout << -1 << " ";
    }
}

Node *inputLevelOrder()
{
    Node *root;
    int value;
    cin >> value;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);

    queue<Node *> nodes;
    if (root)
        nodes.push(root);

    while (!nodes.empty())
    {
        Node *frontNode = nodes.front();
        nodes.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1)
        {
            Node *leftNode = new Node(left);
            frontNode->left = leftNode;
            nodes.push(leftNode);
        }
        if (right != -1)
        {
            Node *rightNode = new Node(right);
            frontNode->right = rightNode;
            nodes.push(rightNode);
        }
    }
    return root;
}

bool search(Node *root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return search(root->left, value);
    if (value > root->value)
        return search(root->right, value);
}

void insertNode(Node *&root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
    }
    if (value < root->value)
    {
        if (root->left == NULL)
            root->left = new Node(value);
        else
            insertNode(root->left, value);
    }
    else if (value > root->value)
    {
        if (root->right == NULL)
            root->right = new Node(value);
        else
            insertNode(root->right, value);
    }
}

int main()
{
    Node *root = inputLevelOrder();

    insertNode(root, 9);

    printLevelOrder(root);

    return 0;
}