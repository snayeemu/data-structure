#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<int> count(26);
    for (char c : str)
    {
        int index = c - 'a';
        count[index]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i])
        {
            char ch = i + 'a';
            cout << ch << " : " << count[i] << endl;
        }
    }

    return 0;
}