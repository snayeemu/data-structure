#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> numbers(size);
    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    bool isDuplicate = false;

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < size - 1; i++)
        if (numbers[i] == numbers[i + 1])
        {
            isDuplicate = true;
            break;
        }

    cout << (isDuplicate ? "YES" : "NO") << endl;

    return 0;
}