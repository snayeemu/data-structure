#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> myList = {10, 20, 30};

    myList.resize(2);
    myList.resize(5);

    for (int value : myList)
        cout << value << " ";
    cout << endl;

    return 0;
}