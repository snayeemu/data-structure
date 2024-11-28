#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> vec(size);

    int count = 0;

    for (int i = 0; i < size; i++)
        cin >> vec[i];

    for (int number : vec)
    {
        if (find(vec.begin(), vec.end(), number + 1) != vec.end())
            count++;
    }

    cout << count << endl;

    return 0;
}