#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size, numberOfQueries;
    cin >> size >> numberOfQueries;
    vector<long long int> numbers(size);
    bool found = false;
    for (int i = 0; i < size; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numberOfQueries; i++)
    {
        long long int number;
        cin >> number;
        bool found = false;
        int index = numbers.size() / 2;

        int start = 0, end = numbers.size() - 1;
        while (start <= end)
        {
            // cout << "numbers: ";
            // for (int number : numbers)
            //     cout << number << " ";
            // cout << endl;

            if (numbers[index] == number)
            {
                found = true;
                break;
            }
            else if (numbers[index] > number)
            {
                end = index - 1;
            }
            else if (numbers[index] < number)
            {
                start = index + 1;
            }
            index = (start + end) / 2;
        }
        cout << (found ? "found" : "not found") << endl;
    }

    return 0;
}