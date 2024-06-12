#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 9};
    auto it = find(v.begin(), v.end(), 9);

    if (it != v.end())
        cout << *it << " is found" << endl;
    else
        cout << 9 << " is not found" << endl;

    return 0;
}