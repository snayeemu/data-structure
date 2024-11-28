#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sizeOfStack, sizeOfQueue;
    cin >> sizeOfStack >> sizeOfQueue;
    stack<int> stk;
    queue<int> que;

    for (int i = 0; i < sizeOfStack; i++)
    {
        int value;
        cin >> value;
        stk.push(value);
    }

        for (int i = 0; i < sizeOfQueue; i++)
    {
        int value;
        cin >> value;
        que.push(value);
    }

    bool isSame = true;

    if (sizeOfQueue != sizeOfStack)
        isSame = false;
    else
        while (sizeOfQueue--)
        {
            int top = stk.top();
            int front = que.front();
            if (top != front)
            {
                isSame = false;
                break;
            }
            stk.pop();
            que.pop();
        }

    cout << (isSame ? "YES" : "NO");

    return 0;
}