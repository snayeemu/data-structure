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

bool isPerfect(Node *root)
{
    queue<Node *> nodes;
    if (root)
        nodes.push(root);

    int level = 0;

    while (!nodes.empty())
    {
        int n = nodes.size();
        Node *front = nodes.front();

        if (!(pow(2, level) == n))
            return false;

        level++;

        for (int i = 0; i < n; i++)
        {
            front = nodes.front();
            nodes.pop();
            if (front->left)
                nodes.push(front->left);
            if (front->right)
                nodes.push(front->right);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = inputLevelOrder();

    cout << (isPerfect(root) ? "YES" : "NO");

    return 0;
}
