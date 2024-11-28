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
};

int main()
{
    linkedList *ls = new linkedList();

    // int value = 0;

    // while (value != -1)
    // {
    //     cout << "Enter a value in the linked list or -1 to exit" << endl;
    //     cin >> value;
    //     if (value == -1)
    //         continue;
    //     ls->push(value);
    // }

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

    Node *temp = new Node;
    temp = ls->head;

    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }

    return 0;
}