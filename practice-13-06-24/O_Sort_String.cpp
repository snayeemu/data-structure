#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int length;
    cin >> length;

    vector<int> frequency(26);

    char c;

    for (int i = 0; i < length; i++)
    {

        cin >> c;
        int index = c - 'a';
        frequency[index]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] > 0)
        {
            char c = i + 'a';
            for (int j = 0; j < frequency[i]; j++)
                cout << c;
        }
    }

    return 0;
}