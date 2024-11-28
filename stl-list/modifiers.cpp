#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> myList = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    vector<int> v = {100, 200, 300, 400};

    myList.pop_back();
    myList.pop_front();
    myList.insert(next(myList.begin(), 3), v.begin(), v.end());
    myList.erase(next(myList.begin(), 2), next(myList.begin(), 5));
    replace(myList.begin(), myList.end(), 30, 100);

    for (int value : myList)
        cout << value << " ";
    cout << endl;

    return 0;
}