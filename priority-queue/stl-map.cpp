#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> mp;
    mp.insert({"Sakib Al Hasan", 75});
    mp.insert({"Tamim Iqbal", 19});
    mp.insert({"Shamim", 13});

    mp["Sakib Al Hasan"] = 79;
    mp["akib"] = 100;

    cout << mp["Shamim"] << endl;

    if (mp.count("akib"))
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    return 0;
}