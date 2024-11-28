#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;
    Node *tail = NULL;

    Node(int value)
    {
        (*this).value = value;
    }

    void add(int value, Node *previous)
    {
        Node *node = new Node(value);
        previous->next = node;
        tail = node;
    }
};

int main()
{
    Node *head = new Node(6);

    head->tail->add(6, head->tail);

    cout << head->value << " " << head->next->value;

    return 0;
}