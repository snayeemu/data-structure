#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80};
    list<int> myList(v.begin(), v.end());

    for (auto it = myList.begin(); it != myList.end(); it++)
        cout << *it << " ";
    cout << endl;

    for (int value : myList)
        cout << value << " ";
    cout << endl;

    return 0;
}