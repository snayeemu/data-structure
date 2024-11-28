#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int> s;
    void push(int value)
    {
        s.push_back(value);
    }

    int pop()
    {
        int value = s.back();
        s.pop_back();
        return value;
    }

    int top()
    {
        int value = s.back();
        return value;
    }

    int size()
    {
        return s.size();
    }

    bool empty()
    {
        return s.empty();
    }
};

bool isSame(Stack s1, Stack s2)
{
    if (s1.size() != s2.size())
        return false;

    int size = s1.size();

    while (size--)
    {
        if (s1.pop() != s2.pop())
            return false;
    }

    return true;
}

int main()
{
    int size1;
    cin >> size1;

    Stack s1;

    while (size1--)
    {
        int value;
        cin >> value;
        s1.push(value);
    }

    int size2;
    cin >> size2;

    Stack s2;

    while (size2--)
    {
        int value;
        cin >> value;
        s2.push(value);
    }

    cout << (isSame(s1, s2) ? "YES" : "NO");

    return 0;
}