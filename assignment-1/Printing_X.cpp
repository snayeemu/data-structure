#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number;
    cin >> number;

    int leftSpace = 0, insideSpace = number - 2;

    while (insideSpace > 0)
    {
        for (int i = 0; i < leftSpace; i++)
            cout << " ";
        leftSpace++;

        cout << '\\';

        for (int i = 0; i < insideSpace; i++)
            cout << " ";
        insideSpace -= 2;

        cout << "/\n";
    }

    for (int i = 0; i < leftSpace; i++)
        cout << " ";
    cout << "X\n";
    leftSpace--;
    insideSpace = 1;

    while (leftSpace >= 0)
    {
        for (int i = 0; i < leftSpace; i++)
            cout << " ";
        leftSpace--;

        cout << "/";

        for (int i = 0; i < insideSpace; i++)
            cout << " ";
        insideSpace += 2;
        cout << "\\\n";
    }

    return 0;
}