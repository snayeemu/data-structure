#include <bits/stdc++.h>
using namespace std;

void print(list<int> numbers)
{
    cout << "L -> ";
    for (int number : numbers)
    {
        cout << number << " ";
    }
    cout << endl;

    cout << "R -> ";
    auto endPointer = numbers.end();
    while (true)
    {
        if (numbers.size() == 0)
            break;
        endPointer--;
        cout << *endPointer << " ";
        if (endPointer == numbers.begin())
            break;
    }
    cout << endl;
}

int main()
{
    list<int> numbers;
    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int option, number;
        cin >> option >> number;

        if (option == 0)
        {
            numbers.push_front(number);
            print(numbers);
        }
        else if (option == 1)
        {
            numbers.push_back(number);
            print(numbers);
        }
        else if (option == 2)
        {
            int size = numbers.size();

            if (number >= size || number < 0)
            {
                print(numbers);
                continue;
            }

            numbers.erase(next(numbers.begin(), number));
            print(numbers);
        }
    }

    return 0;
}