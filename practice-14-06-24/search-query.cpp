#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    int queries;
    cin >> queries;

    sort(numbers.begin(), numbers.end());

    while (queries--)
    {
        int number;
        cin >> number;

        int leftIndex = 0, rightIndex = size - 1;

        bool found = false;

        while (leftIndex <= rightIndex)
        {
            int midIndex = (leftIndex + rightIndex) / 2;
            if (numbers[midIndex] == number)
            {
                found = true;
                break;
            }
            else if (number < numbers[midIndex])
                rightIndex = midIndex - 1;
            else if (number > numbers[midIndex])
                leftIndex = midIndex + 1;
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}