#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        int n;
        cin >> n;
        set<int> numbers;
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            numbers.insert(value);
        }
        for (int value : numbers)
            cout << value << " ";
        cout << endl;
    }

    return 0;
}