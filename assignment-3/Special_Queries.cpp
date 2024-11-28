#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numberOfQueries;
    cin >> numberOfQueries;
    queue<string> names;

    while (numberOfQueries--)
    {
        int option;
        cin >> option;
        if (option == 0)
        {
            string name;
            cin >> name;
            names.push(name);
        }
        else if (option == 1)
        {
            if (!names.empty())
            {
                string name = names.front();
                names.pop();
                cout << name << endl;
            }
            else
                cout << "Invalid" << endl;
        }
    }

    return 0;
}