#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size1;
    cin >> size1;
    vector<int> arrayOfNumbers1(size1);
    for (int i = 0; i < size1; i++)
        cin >> arrayOfNumbers1[i];
    
    int size2;
    cin >> size2;
    vector<int> arrayOfNumbers2(size2);
    for (int i = 0; i < size2; i++)
        cin >> arrayOfNumbers2[i];

    int toBeInsertedAt;
    cin >> toBeInsertedAt;

    arrayOfNumbers1.insert(arrayOfNumbers1.begin() + toBeInsertedAt, arrayOfNumbers2.begin(), arrayOfNumbers2.end());

    for(int number: arrayOfNumbers1) cout << number << " ";
    

    return 0;
}