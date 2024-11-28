#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *prev = NULL;
    Node *next = NULL;
};

class linkedList
{
public:
    Node *head, *tail;
    int size;

    linkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
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
        size++;
    }

    void print()
    {
        Node *temp = head;
        cout << "L -> ";
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

        if (position > size)
        {
            cout << "Invalid" << endl;
            return;
        }

        for (int i = 0; i < position - 1; i++)
        {
            previous = previous->next;
            if (previous == NULL)
            {
                cout << "Invalid" << endl;
                return;
            }
        }
        if (previous == tail)
        {
            push(value);
            print();
            printReverse();
            return;
        }

        current = previous->next;

        Node *newNode = new Node;
        newNode->value = value;
        previous->next = newNode;
        current->prev = newNode;
        newNode->next = current;
        newNode->prev = previous;

        print();
        printReverse();
        size++;
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
            print();
            printReverse();
            size++;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        print();
        printReverse();

        size++;
    }

    void deleteAt(int position)
    {

        if (head == NULL)
            return;
        if (position == size - 1)
        {
            deleteTail();
            return;
        }

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
        toDelete->next->prev = previous;

        delete toDelete;
        size--;
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
        size--;
    }

    void deleteTail()
    {
        Node *toDelete = tail;
        if (tail == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        delete toDelete;
        size--;
    }

    void printReverse()
    {
        Node *temp = tail;

        cout << "R -> ";
        while (temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void reverse()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            Node *next = temp->next;
            temp->next = temp->prev;
            temp->prev = next;
            temp = temp->next;
        }
        temp = tail;
        tail = head;
        head = temp;
    }

    void reverseValue()
    {
        Node *start = head, *end = tail;

        while (start != end)
        {
            swap(start->value, end->value);
            start = start->next;
            end = end->prev;
            if (start->next != end)
                break;
        }
    }

    bool detectCycle()
    {
        Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main()
{
    linkedList *ls = new linkedList;
    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int value, index;
        cin >> index >> value;
        ls->insert(value, index);
    }

    return 0;
}