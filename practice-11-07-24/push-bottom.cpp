#include <bits/stdc++.h>
using namespace std;

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> copyStack;

    int size = myStack.size();

    for (int i = 0; i < size; i++)
    {
        int top = myStack.top();
        myStack.pop();
        copyStack.push(top);
    }

    myStack.push(x);

    for (int i = 0; i < size; i++)
    {
        int top = copyStack.top();
        copyStack.pop();
        myStack.push(top);
    }

    return myStack;
}

int main()
{

    return 0;
}