#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;
};

class Stack
{
public:
    Node *head = new Node;
    Stack()
    {
        this->head = NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->value;
    }

    void pop()
    {
        if (head == NULL)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack *numbers = new Stack;
    int length;
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        int number;
        cin >> number;
        numbers->push(number);
    }

    int index;
    cin >> index;

    for (int i = 0; i < length - index; i++)
        numbers->pop();

    cout << numbers->top();

    delete numbers;

    return 0;
}