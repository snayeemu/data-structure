#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfValues;
    cin >> numberOfValues;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (numberOfValues--)
    {
        int value;
        cin >> value;
        pq.push(value);
    }

    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int query;
        cin >> query;
        if (query == 0)
        {
            int value;
            cin >> value;
            pq.push(value);
            cout << pq.top() << endl;
        }
        else if (query == 1)
            if (!pq.empty())
                cout << pq.top() << endl;
            else
                cout << "Empty" << endl;
        else if (query == 2)
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                    cout << pq.top() << endl;
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
    }

    return 0;
}