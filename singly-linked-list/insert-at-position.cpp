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
        if(this->head == NULL)
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

int main()
{
    linkedList *ls = new linkedList();

    string values;

    cout << "Enter a values in the linked list: ";
    getline(cin, values);

    stringstream ss(values);

    string number;
    while (ss >> number)
    {
        int numberInInt = stoi(number);
        ls->push(numberInInt);
    }

    int option = 0;

    while (option != -1)
    {
        cout << endl
             << endl
             << "1 to print\n2 to insert\n3 to insert at head\n4 to insert at tail\n5 to delete\n-1 to exit" << endl;

        cin >> option;

        if (option == 1)
        {
            ls->print();
        }
        else if (option == 2)
        {
            int value, insertAt;

            cout << "Enter value and the position: ";
            cin >> value >> insertAt;

            ls->insert(value, insertAt);
        }
        else if (option == 3)
        {
            int value;

            cout << "Enter value and the position: ";
            cin >> value;

            ls->insertAtHead(value);
        }
        else if (option == 4)
        {
            int value;
            cin >> value;
            ls->push(value);
        }
        else if (option == 5)
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            ls->deleteAt(position);
        }
        else if (option == -1)
            break;
    }

    return 0;
}