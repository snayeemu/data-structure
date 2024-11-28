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

int maxHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = inputLevelOrder();
    int height = maxHeight(root);

    cout << height;

    return 0;
}