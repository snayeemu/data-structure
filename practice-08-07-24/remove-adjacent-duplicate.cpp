#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> outputString;

        for (char c : s)
            if (outputString.empty())
                outputString.push(c);
            else if (c != outputString.top())
                outputString.push(c);
            else
                outputString.pop();

        string output = "";

        while (!outputString.empty())
        {
            output = outputString.top() + output;
            outputString.pop();
        }

        return output;
    }
};

int main()
{
    Solution sl;

    cout << (sl.removeDuplicates("abbaca"));

    return 0;
}