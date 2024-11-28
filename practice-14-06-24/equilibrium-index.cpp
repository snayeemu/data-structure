#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    int i = 1;

    while (i < size-1)
    {
        int leftSum = 0, rightSum = 0;
        for (int j = 0; j < i; j++)
            leftSum += numbers[j];
        for (int j = i + 1; j < size; j++)
            rightSum += numbers[j];
        if (leftSum == rightSum)
        {
            cout << i;
            break;
        }
        i++;
    }

    return 0;
}