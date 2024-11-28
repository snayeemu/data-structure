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

                return;
            }
        }
        if (previous->next == NULL)
        {

            return;
        }
        toDelete = previous->next;
        previous->next = previous->next->next;
        if (previous->next == NULL)
        {
            tail = previous;
        }
        delete toDelete;
    }

    void deleteHead()
    {
        if (this->head == NULL)
        {

            return;
        }
        Node *previousHead = new Node;
        previousHead = head;
        head = head->next;
        if (head == NULL)
            this->tail = NULL;
        delete previousHead;
    }

    void removeDuplicate()
    {
        vector<int> values;

        Node *temp = new Node;
        temp = this->head;
        int index = 0;
        while (temp != NULL)
        {

            if (find(values.begin(), values.end(), temp->value) != values.end())
            {
                temp = temp->next;
                this->deleteAt(index);
            }
            else
            {
                index++;
                values.push_back(temp->value);
                temp = temp->next;
            }
        }
    }
};

int main()
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

    ls->removeDuplicate();

    ls->print();

    return 0;
}