#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inputStr;
    cin >> inputStr;
    stack<char> inputStk;

    for (char c : inputStr)
        inputStk.push(c);

    while (!inputStk.empty())
    {
        char top = inputStk.top();
        inputStk.pop();
        cout << top;
    }

    return 0;
}