#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> charStack;

        for (char c : s)
        {
            if (c == ')' || c == ']' || c == '}')
            {
                if (charStack.empty())
                    return false;
                else if (c == ')' && charStack.top() == '(')
                    charStack.pop();
                else if (c == ']' && charStack.top() == '[')
                    charStack.pop();
                else if (c == '}' && charStack.top() == '{')
                    charStack.pop();
                else
                    return false;
            }
            else
                charStack.push(c);
        }

        if (!charStack.empty())
            return false;

        return true;
    }
};

int main()
{

    return 0;
}