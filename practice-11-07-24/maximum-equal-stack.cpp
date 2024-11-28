#include <bits/stdc++.h>
using namespace std;

int sumOfStack(stack<int> stk)
{
    int size = stk.size();
    int sum = 0;

    while (size--)
    {
        sum += stk.top();
        stk.pop();
    }
    return sum;
}

int maxSum(stack<int> &stk1, stack<int> &stk2, stack<int> &stk3)
{
    int sum1 = sumOfStack(stk1);
    int sum2 = sumOfStack(stk2);
    int sum3 = sumOfStack(stk3);

    while (!stk1.empty() && !stk2.empty() && !stk3.empty())
    {
        if (sum1 == sum2 && sum1 == sum3)
            return sum1;
        else if (sum1 >= sum2 && sum1 >= sum3)
        {
            int top = stk1.top();
            stk1.pop();
            sum1 -= top;
        }
        else if (sum2 >= sum1 && sum2 >= sum3)
        {
            int top = stk2.top();
            stk2.pop();
            sum2 -= top;
        }
        else if (sum3 >= sum1 && sum3 >= sum1)
        {
            int top = stk3.top();
            stk3.pop();
            sum3 -= top;
        }
    }

    return 0;
}

int main()
{
    stack<int> stk1, stk2, stk3;

    int number;
    while ((cin >> number) && number != -1)
    {
        stk1.push(number);
    }

    while ((cin >> number) && number != -1)
    {
        stk2.push(number);
    }

    while ((cin >> number) && number != -1)
    {
        stk3.push(number);
    }

    cout << (maxSum(stk1, stk2, stk3));

    return 0;
}