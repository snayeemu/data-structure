#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    map<string, int> mp;

    while (ss >> word)
        mp[word]++;

    cout << mp["foot"] << endl;



    return 0;
}