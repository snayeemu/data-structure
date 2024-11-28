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

void printOuterLeft(Node *root)
{
    if (root == NULL)
        return;

    if (root->left)
        printOuterLeft(root->left);
    else
        printOuterLeft(root->right);
    cout << root->value << " ";
}

void printOuterRight(Node *root)
{
    if (root == NULL)
        return;

    cout << root->value << " ";
    if (root->right)
        printOuterRight(root->right);
    else
        printOuterRight(root->left);
}

void printOuterLevel(Node *root)
{
    if (root == NULL)
        return;
    if (root->left)
        printOuterLeft(root->left);
    cout << root->value << " ";
    if (root->right)
        printOuterRight(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = inputLevelOrder();
    printOuterLevel(root);

    return 0;
}
