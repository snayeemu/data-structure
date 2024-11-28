#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    cin >> length;
    vector<int> numbers;

    for (int i = 0; i < length; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    int maximum;
    for (int i = 0; i < length; i++)
    {
        maximum = numbers[i + 1];
        for (int j = i + 2; j < length; j++)
        {
            if (numbers[j] > maximum)
                maximum = numbers[j];
        }
        cout << maximum << " ";
    }

    return 0;
}