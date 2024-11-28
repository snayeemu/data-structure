#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> st;
    queue<int> que;

    int sizeOfStack;

    cin >> sizeOfStack;

    while (sizeOfStack--)
    {
        int value;
        cin >> value;
        st.push(value);
    }

    int sizeOfQueue;
    cin >> sizeOfQueue;

    while (sizeOfQueue--)
    {
        int value;
        cin >> value;
        que.push(value);
    }

    sizeOfStack = st.size();
    sizeOfQueue = que.size();

    bool isSame = true;

    if (sizeOfQueue != sizeOfStack)
        isSame = false;
    else
        while (sizeOfStack--)
        {
            int qValue = que.front();
            int sValue = st.top();

            if (qValue != sValue)
            {
                isSame = false;
                break;
            }
            que.pop();
            st.pop();
        }

    cout << (isSame ? "YES" : "NO");

    return 0;
}