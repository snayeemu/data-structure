#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;
    Node *prev = NULL;
};

class List
{
public:
    Node *head = new Node;
    Node *tail = new Node;
    int length;

    List()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void pushBack(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void popBack()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        length--;
    }

    void pushFront(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void popFront()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            Node *temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            length--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            length--;
        }
    }

    void insertAt(int position, int value)
    {
        if (position == 0)
        {
            pushFront(value);
            return;
        }
        else if (position > length || position < 0)
            cout << "Invalid position";
        else if (position == length)
            pushBack(value);
        else
        {
            Node *temp = head;
            for (int i = 0; i < position - 1; i++)
                temp = temp->next;
            Node *newNode = new Node;
            newNode->value = value;
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            length++;
        }
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    List *doubly = new List;

    for (int i = 0; i < 5; i++)
    {
        int number;
        cin >> number;
        doubly->pushBack(number);
    }

    doubly->popBack();
    doubly->pushFront(10);
    doubly->insertAt(4, 11);
    doubly->popFront();

    doubly->print();
    cout << endl
         << doubly->length;

    return 0;
}