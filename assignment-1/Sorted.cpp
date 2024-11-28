#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size, numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        cin >> size;
        vector<int> numbers(size);
        for (int i = 0; i < size; i++)
            cin >> numbers[i];

        vector<int> sorterNumbers(numbers.begin(), numbers.end());
        sort(sorterNumbers.begin(), sorterNumbers.end());
        bool sorted = true;
        for (int i = 0; i < size; i++)
            if (numbers[i] != sorterNumbers[i])
            {
                sorted = false;
                break;
            }

        cout << (sorted ? "YES" : "NO") << endl;
    }

    return 0;
}