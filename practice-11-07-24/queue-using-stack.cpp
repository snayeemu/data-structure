#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> values;
    MyQueue()
    {
    }

    void push(int x)
    {
        values.push(x);
    }

    int pop()
    {
        stack<int> reversedValues;
        int size = values.size();
        for (int i = 0; i < size; i++)
        {
            int top = values.top();
            values.pop();
            reversedValues.push(top);
        }
        int popped = reversedValues.top();
        reversedValues.pop();

        size = reversedValues.size();
        for (int i = 0; i < size; i++)
        {
            int top = reversedValues.top();
            reversedValues.pop();
            values.push(top);
        }

        return popped;
    }

    int peek()
    {
        stack<int> reversedValues;
        int size = values.size();
        for (int i = 0; i < size; i++)
        {
            int top = values.top();
            values.pop();
            reversedValues.push(top);
        }
        int peek = reversedValues.top();

        size = reversedValues.size();
        for (int i = 0; i < size; i++)
        {
            int top = reversedValues.top();
            reversedValues.pop();
            values.push(top);
        }

        return peek;
    }

    bool empty()
    {
        return values.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue mq;

    mq.push(1);
    mq.push(2);

    cout << (mq.peek());

    return 0;
}