#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> insert = {9, 8, 7, 6, 5};

    v.insert(v.begin() + 3, insert.begin(), insert.end());

    for (int number : v)
        cout << number << " ";

    return 0;
}