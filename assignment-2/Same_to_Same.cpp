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
};

bool isSame(linkedList *l1, linkedList *l2)
{
    Node *nodeOfList1 = l1->head, *nodeOfList2 = l2->head;

    while (nodeOfList1 != NULL && nodeOfList2 != NULL)
    {
        if (nodeOfList1->value != nodeOfList2->value)
        {
            return false;
        }

        nodeOfList1 = nodeOfList1->next;
        nodeOfList2 = nodeOfList2->next;
    }
    if (nodeOfList1 != NULL || nodeOfList2 != NULL)
        return false;
    return true;
}

int main()
{
    linkedList *ls1 = new linkedList();
    linkedList *ls2 = new linkedList();

    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        ls1->push(value);
    }

    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        ls2->push(value);
    }

    cout << (isSame(ls1, ls2) ? "YES" : "NO") << endl;

    return 0;
}