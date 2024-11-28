#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *headPointer = new Node;

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

    void insertAtHead(int value)
    {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = this->head;
        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
            return;
        }
        this->head = newNode;
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
            {

                return;
            }
        }

        toDelete = previous->next;
        if (toDelete == NULL)
            return;
        previous->next = toDelete->next;
        if (toDelete == tail)
        {
            tail = previous;
        }
        delete toDelete;
    }

    void deleteHead()
    {
        if (this->head == NULL)
            return;

        Node *previousHead = new Node;
        previousHead = head;
        head = head->next;
        if (head == NULL)
            this->tail = NULL;
        delete previousHead;
    }

    void reverse(Node *head)
    {
        Node *temp = head;

        if (temp == tail)
        {
            this->head = temp;
            return;
        }
        reverse(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
        // if(temp->next == temp->next->next->next)
        //     temp->next = NULL;
    }
};

int main()
{
    linkedList *ls = new linkedList();
    int option, value, numberOfQueries;

    while (true)
    {

        cin >> value;
        if (value == -1)
            break;
        ls->push(value);
    }

    ls->reverse(ls->head);
    ls->print();

    return 0;
}