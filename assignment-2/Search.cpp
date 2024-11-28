#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

class linkedList
{
public:
    Node *head, *tail;

    linkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void push(int value)
    {
        Node *temp = new Node;
        temp->value = value;
        temp->next = NULL;

        if (head == NULL)
        {

            this->head = temp;
            this->tail = temp;
        }
        else
        {

            tail->next = temp;
            tail = temp;
        }
    }

    void insert(int value, int position)
    {
        Node *previous = this->head;
        Node *current = NULL;

        if (position == 0)
        {
            this->insertAtHead(value);
            return;
        }

        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
            if (previous == NULL)
            {
                cout << "Invalid position!!!" << endl;
                return;
            }
        }
        current = previous->next;

        Node *newNode = new Node;
        newNode->value = value;
        previous->next = newNode;
        newNode->next = current;
    }

    void print()
    {
        Node *temp = new Node;
        temp = this->head;

        cout << "\n\nValues of the list are: ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = this->head;
        this->head = newNode;
    }

    void deleteAt(int position)
    {
        Node *previous, *toDelete;
        previous = head;

        if (position == 0)
        {
            this->deleteHead();
            return;
        }

        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
            if (previous == NULL)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }
        if (previous->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        toDelete = previous->next;
        previous->next = previous->next->next;
        delete toDelete;
    }

    void deleteHead()
    {
        if (this->head == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *previousHead = new Node;
        previousHead = head;
        head = head->next;
        delete previousHead;
    }

    int findIndexOf(int value)
    {
        Node *temp = new Node;
        temp = this->head;

        int index = 0;
        while (true)
        {
            if (temp->value == value)
                return index;
            index++;
            temp = temp->next;
            if (temp == NULL)
                return -1;
        }
    }
};

int main()
{
    int numberOfTestCases;

    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        linkedList *ls = new linkedList();

        while (true)
        {
            int value;
            cin >> value;
            if (value == -1)
                break;
            ls->push(value);
        }

        int value;
        cin >> value;

        cout << (ls->findIndexOf(value)) << endl;
    }

    return 0;
}