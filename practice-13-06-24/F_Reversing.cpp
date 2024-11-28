#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> vec(size);

    for(int i = 0; i < size; i++) cin >> vec[i];

    for(auto it = vec.end() - 1; it != vec.begin() - 1; it--)
        cout << *it << " ";

    return 0;
}