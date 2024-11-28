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

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    int nodesInRightSubTree = countNodes(root->left);
    int nodesInLeftSubTree = countNodes(root->right);
    return nodesInLeftSubTree + nodesInRightSubTree + 1;
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

int countLeafNodes(Node *root, int &numberOfLeaf)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        numberOfLeaf++;
    countLeafNodes(root->left, numberOfLeaf);
    countLeafNodes(root->right, numberOfLeaf);
    return numberOfLeaf;
}

int countLeafNodes2(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
    {
        int leftLeafs = countLeafNodes2(root->left);
        int rightLeafs = countLeafNodes2(root->right);
        return leftLeafs + rightLeafs;
    }
}

int main()
{
    Node *root = inputLevelOrder();
    int numberOfNodes = countNodes(root);
    

    cout << countLeafNodes2(root);

    return 0;
}