#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;

    Node(int value)
    {
        (*this).value = value;
    }
};

int main()
{
    Node *head = new Node(10);
    Node *b = new Node(20);

    head->next = b;

    cout << head->value << ' ' << (head->next)->value << endl;

    return 0;
}