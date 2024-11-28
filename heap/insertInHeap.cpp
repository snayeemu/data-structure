#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    int n;
    cin >> n;
    // int value;
    // cin >> value;
    // v.push_back(value);

    for (int i = 0; i < n; i++)
    {
        int inputValue;
        cin >> inputValue;
        v.push_back(inputValue);
        int currentIndex = v.size() - 1;
        int parentIndex = (currentIndex - 1) / 2;

        while (v[currentIndex] > v[parentIndex])
        {
            swap(v[currentIndex], v[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }

    for (auto value : v)
        cout << value << " ";

    return 0;
}