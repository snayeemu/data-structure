#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    while (true)
    {
        int flag;
        cin >> flag;

        if (flag == 0)
        {
            int value;
            cin >> value;
            pq.push(value);
        }
        else if (flag == 1)
            pq.pop();
        else if (flag == 2)
            cout << pq.top() << endl;
        else
            break;
    }

    return 0;
}