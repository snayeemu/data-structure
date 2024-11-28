#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> firstString, secondString;

        for (char c : s)
            if (c == '#' && firstString.empty())
                continue;
            else if (c == '#')
                firstString.pop();
            else
                firstString.push(c);

        for (char c : t)
            if (c == '#' && secondString.empty())
                continue;
            else if (c == '#')
                secondString.pop();
            else
                secondString.push(c);
        return firstString == secondString;
    }
};

int main()
{
    Solution sl;

    cout << (sl.backspaceCompare("ab#c", "ad#c"));

    return 0;
}