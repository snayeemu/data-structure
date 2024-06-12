#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 999999;
    cin >> size;
    cin.ignore();
    vector<string> strs(size);

    for (int i = 0; i < size; i++)
        getline(cin, strs[i]);
    
    for (string str : strs)
        cout << str << endl;
    

    return 0;
}