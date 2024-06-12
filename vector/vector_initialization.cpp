#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v; // vector of initial size 0
    vector<int> v(5); // vector of initial size 5 and value 0
    vector<int> v(5, 10); // vector of initial size 5 and value 10
    vector<int> v2(v); // vector v2 is initialized with values of vector v 
    int a[] = {0, 1, 2, 3, 4, 5, 5};
    vector<int> v3(a, a+6); // vector v3 is initialized with values of array a 


    return 0;
}