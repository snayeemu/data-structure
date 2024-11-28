#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> values;
    // queue<int> valuesReversed;
    MyStack()
    {
    }

    void push(int x)
    {
        values.push(x);
    }

    int pop()
    {
        int size = values.size();
        for (int i = 0; i < size - 1; i++)
        {
            int front = values.front();
            values.pop();
            values.push(front);
        }
        int front = values.front();
        values.pop();
        return front;
    }

    int top()
    {
        return values.back();
    }

    bool empty()
    {
        return values.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{

    MyStack ms;

    ms.push(1);

    cout << (ms.empty());

    return 0;
}