#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> history;

    while (true)
    {
        string website;
        cin >> website;
        if (website == "end")
            break;
        history.push_back(website);
    }

    int numberOfQueries;
    cin >> numberOfQueries;
    getchar();
    int index = 0;

    while (numberOfQueries--)
    {
        string query;
        getline(cin, query);
        auto it = query.find("visit");
        if (it != -1)
        {
            stringstream ss(query);
            string websiteName;
            string word;
            while (ss >> word)
                websiteName = word;

            auto websitePointer = find(history.begin(), history.end(), websiteName);
            if (websitePointer == history.end())
            {
                cout << "Not Available" << endl;
                continue;
            }
            else
                cout << websiteName << endl;

            index = 0;

            for (auto i = history.begin(); i != history.end(); i++)
            {
                if (i == websitePointer)
                    break;
                index++;
            }
        }
        else if (query == "next")
        {
            int size = history.size();
            if (size <= index + 1)
            {
                cout << "Not Available" << endl;
                continue;
            }
            index++;
            auto websiteName = next(history.begin(), index);
            cout << *websiteName << endl;
        }
        else if (query == "prev")
        {
            if (index - 1 == -1)
            {
                cout << "Not Available" << endl;
                continue;
            }
            index--;
            auto websiteName = next(history.begin(), index);
            cout << *websiteName << endl;
        }
    }

    return 0;
}