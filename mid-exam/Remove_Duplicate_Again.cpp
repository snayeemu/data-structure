#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> numbers;

    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        numbers.push_back(value);
    }

    numbers.sort();

    numbers.unique();
    for (int number : numbers)
        cout << number << " ";

    return 0;
}