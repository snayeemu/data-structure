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
        string binary;
        int test = 0;
        cin >> binary;

        for (int i = 0; i < binary.length() - 1; i++)
        {
            if (binary[i] == '1' && binary[i + 1] == '0')
                test++;
            else if (i + 1 == binary.length() - 1 && binary[i + 1] == '1')
                test++;

            if (test > 1)
                break;
            ;
        }
        cout << (test == 1 ? "YES" : "NO") << endl;
    }

    return 0;
}