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

void sumExceptLeaf(Node *root, int &sum)
{
    if (root == NULL)
        return;
    if (root->left || root->right)
        sum += root->value;
    sumExceptLeaf(root->left, sum);
    sumExceptLeaf(root->right, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Node *root = inputLevelOrder();
    int sum = 0;
    sumExceptLeaf(root, sum);
    cout << sum;
    return 0;
}

