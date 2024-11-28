#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size1;
    cin >> size1;
    queue<int> queue1;

    while (size1--)
    {
        int value;
        cin >> value;
        queue1.push(value);
    }

    int size2;
    cin >> size2;
    queue<int> queue2;

    while (size2--)
    {
        int value;
        cin >> value;
        queue2.push(value);
    }

    size2 = queue2.size();

    while (size2--)
    {
        queue1.push(queue2.front());
        queue2.pop();
    }

    size1 = queue1.size();

    while (size1--)
    {
        cout << queue1.front() << " ";
        queue1.pop();
    }

    return 0;
}