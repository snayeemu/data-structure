#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfTestCases;

    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        string numbers;
        cin >> numbers;
        stack<int> values;

        for (char number : numbers)
        {
            int intNumber = number - '0';
            if (values.empty() || values.top() == intNumber)
                values.push(intNumber);
            else
                values.pop();
        }
        cout << (values.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}