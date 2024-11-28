#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases;
    cin >> numberOfTestCases;
    string ignore;
    getline(cin, ignore);

    while (numberOfTestCases--)
    {
        map<string, int> countWord;
        string sentence;
        getline(cin, sentence);
        // cout << sentence << endl;
        string word;
        stringstream ss(sentence);

        stringstream ss2(sentence);
        ss2 >> word;
        pair<string, int> maxPair;
        int maxValue = 0;

        while (ss >> word)
        {
            countWord[word]++;
            if (countWord[word] > maxValue)
            {
                maxValue = countWord[word];
                maxPair = {word, countWord[word]};
            }
        }

        cout << maxPair.first << " " << maxPair.second << endl;
    }

    return 0;
}