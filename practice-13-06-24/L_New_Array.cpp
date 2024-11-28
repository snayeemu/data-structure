#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> vec1(size), vec2(size);

    for (int i = 0; i < size; i++)
        cin >> vec1[i];
    for (int i = 0; i < size; i++)
        cin >> vec2[i];

    vec2.insert(vec2.end(), vec1.begin(), vec1.end());

    for (int number : vec2)
        cout << number << " ";

    return 0;
}