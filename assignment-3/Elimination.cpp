#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfTestCases;
    cin >> numberOfTestCases;

    while (numberOfTestCases--)
    {
        string binaryNumbers;
        cin >> binaryNumbers;
        stack<char> digits;

        for (char number : binaryNumbers)
        {

            if (!digits.empty() && number == '1' && digits.top() == '0')
                digits.pop();
            else
                digits.push(number);
        }

        cout << (digits.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}