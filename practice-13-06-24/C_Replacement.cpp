#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    vector<int> vec(size);

    for (int i = 0; i < size; i++)
        cin >> vec[i];

    for(auto it = vec.begin(); it != vec.end(); it++)
        if(*it > 0) replace(it, it + 1, *it, 1);
        else if(*it < 0) replace(it, it + 1, *it, 2);

    for(int number: vec) cout << number << " ";

    return 0;
}