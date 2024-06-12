#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {0,1,2,3,4,5,6,7, 8, 9, 10, 11, 12, 13, 14, 15, 9, 8, 7, 8, 8, 8,};

    replace(v.begin(), v.end(), 8, 0);

    for(int number: v) cout << number << " ";

    return 0;
}