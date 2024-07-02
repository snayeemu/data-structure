#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *prev = NULL;
    Node *next = NULL;
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

        if (head == NULL)
        {

            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    void print()
    {
        Node *temp = new Node;
        temp = this->head;

        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int value, int position)
    {
        Node *previous = head;
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
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = previous;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = head;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void deleteAt(int position)
    {

        if (head == NULL)
            return;

        if (position == 0)
        {
            this->deleteHead();
            return;
        }

        Node *previous, *toDelete;
        previous = head;

        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
            if (previous == NULL || previous->next == NULL)
                return;
        }

        toDelete = previous->next;
        if (toDelete == NULL)
            return;
        previous->next = toDelete->next;
        if (toDelete == tail)
            tail = previous;
        else
            toDelete->next->prev = previous;
        delete toDelete;
    }

    void deleteHead()
    {
        if (this->head == NULL)
            return;

        Node *previousHead = head;
        head = head->next;
        if (head == NULL)
            tail = NULL;
        else
            head->prev = NULL;
        delete previousHead;
    }

    void printReverse()
    {
        Node *temp = tail;

        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    linkedList *ls = new linkedList();
    int value;

    // cin >> numberOfQueries;

    // while (numberOfQueries--)
    // {

    //     cin >> option >> value;

    //     if (option == 0)
    //         ls->insertAtHead(value);
    //     else if (option == 1)
    //         ls->push(value);
    //     else if (option == 2)
    //         ls->deleteAt(value);

    //     ls->print();
    // }

    while (true)
    {
        cin >> value;
        if (value == -1)
            break;
        ls->push(value);
    }

    ls->insert(2, 1);
    ls->printReverse();

    delete ls;

    return 0;
}