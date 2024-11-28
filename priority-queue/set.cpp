#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int value;
        cin >> value;
        s.insert(value);
    }

    for (auto it : s)
        cout << it << endl;

    if (s.count(10))
        cout << "Found" << endl;

    return 0;
}