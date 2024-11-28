#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> values, minStack;
    MinStack()
    {
    }

    void push(int val)
    {
        values.push(val);
        if (minStack.empty())
            minStack.push(val);
        else if (minStack.top() > val)
            minStack.push(val);
        else
            minStack.push(minStack.top());
    }

    void pop()
    {
        if (values.empty())
            return;
        int value = values.top();
        values.pop();
        minStack.pop();
    }

    int top()
    {
        return values.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *ms = new MinStack();

    ms->push(0);
    ms->push(1);
    ms->push(0);

    ms->getMin();
    ms->pop();
    ms->getMin();

    return 0;
}