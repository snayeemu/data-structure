#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfElements;
    cin >> numberOfElements;
    vector<int> numbers(numberOfElements);

    for (int i = 0; i < numberOfElements; i++)
    {
        int number;
        cin >> number;
        numbers[i] = number;
    }

    for (int i = 1; i < numberOfElements; i++)
        if (numbers[i] < numbers[i - 1] && numbers[i] < numbers[i + 1])
            cout << numbers[i] << endl;

    return 0;
}