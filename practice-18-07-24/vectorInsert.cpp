#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> numbers;
    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int option;
        int number;
        cin >> option >> number;
        if (numbers.empty())
            numbers.push_back(number);
        else if (option == 1)
        {
            numbers.insert(numbers.begin() + 1, number);
        }
        else if (option == 2)
        {
            numbers.insert(numbers.end() - 1, number);
        }
    }

    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";

    return 0;
}