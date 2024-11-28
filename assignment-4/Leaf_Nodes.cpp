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

void printLeafInDescending(Node *root)
{
    vector<int> leafValues;
    queue<Node *> nodes;
    if (root)
        nodes.push(root);

    while (!nodes.empty())
    {
        Node *frontNode = nodes.front();
        nodes.pop();

        if (frontNode->left == NULL && frontNode->right == NULL)
            leafValues.push_back(frontNode->value);

        if (frontNode->left)
            nodes.push(frontNode->left);
        if (frontNode->right)
            nodes.push(frontNode->right);
    }
    sort(leafValues.begin(), leafValues.end(), greater<int>());
    for (int value : leafValues)
        cout << value << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = inputLevelOrder();
    printLeafInDescending(root);

    return 0;
}
