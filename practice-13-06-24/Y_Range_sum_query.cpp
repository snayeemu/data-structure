#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int size, numberOfPairs;
    cin >> size >> numberOfPairs;
    vector<long long int> numbers(size);
    for (int i = 0; i < size; i++)
        cin >> numbers[i];

    // for (int i = 0; i < numberOfPairs; i++)
    // {
    //     int begin, end;
    //     cin >> begin >> end;
    //     int sum = 0;
    //     // int sum = accumulate(numbers.begin() + begin-1, numbers.begin() + end, 0);
    //     // for(int j = begin-1; j < end; j++) sum += numbers[j];
    //     // cout << sum << endl;
    //     cout << accumulate(numbers.begin() + begin-1, numbers.begin() + end, 0) << endl;
    // }

    vector<long long int> sums(size + 1);

    for (int i = 1; i <= size; i++)
        sums[i] = sums[i - 1] + numbers[i - 1];

    for(int i = 0; i < numberOfPairs; i++)
    {
        long long int begin, end;
        cin >> begin >> end;
        
        cout << sums[end] - sums[begin - 1] << endl;
    }

    return 0;
}