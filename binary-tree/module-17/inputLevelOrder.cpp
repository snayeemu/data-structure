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
        cout << currentNode->value << " ";
        que.pop();

        if (currentNode->left)
        {
            que.push(currentNode->left);
        }
        if (currentNode->right)
        {
            que.push(currentNode->right);
        }
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

int main()
{
    Node *root = inputLevelOrder();
    printLevelOrder(root);

    return 0;
}