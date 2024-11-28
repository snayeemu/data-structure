#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size, numberOfQueries;
    cin >> size >> numberOfQueries;
    vector<int> numbers(size);
    for(int i = 0; i < size; i++) cin >> numbers[i];
    for(int i = 0; i < numberOfQueries; i++)
    {
        int number;
        cin >> number;
        auto it = find(numbers.begin(), numbers.end(), number);
        if(it != numbers.end()) cout << "found" << endl;
        else cout <<  "not found" << endl;
    }

    return 0;
}