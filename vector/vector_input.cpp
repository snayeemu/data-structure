#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        int value;
        cin >> value;
        v.push_back(value);
    }

    for (int value : v)
        cout << value << " ";

    return 0;
}