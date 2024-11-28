#include <bits/stdc++.h>
using namespace std;

vector<int> insertHeap(vector<int> &v)
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int inputValue;
        cin >> inputValue;
        v.push_back(inputValue);
        int currentIndex = v.size() - 1;
        int parentIndex = (currentIndex - 1) / 2;

        while (v[currentIndex] < v[parentIndex])
        {
            swap(v[currentIndex], v[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
    }

    return v;
}

int deleteMax(vector<int> &v)
{
    int returnValue = -1;
    if (!v.empty())
    {
        returnValue = v.front();
        v[0] = v.back();
        v.pop_back();
    }
    int parentIndex = 0;
    int firstChildIndex = (parentIndex * 2) + 1;
    int secondChildIndex = (parentIndex * 2) + 2;

    while ((v.size() > firstChildIndex && v[parentIndex] > v[firstChildIndex]) || (v.size() > secondChildIndex && v[parentIndex] > v[secondChildIndex]))
    {
        if (v.size() > firstChildIndex && v[firstChildIndex] < v[secondChildIndex])
        {
            swap(v[parentIndex], v[firstChildIndex]);
            parentIndex = firstChildIndex;
        }
        else if (v.size() > secondChildIndex)
        {
            swap(v[parentIndex], v[secondChildIndex]);
            parentIndex = secondChildIndex;
        }
        else
            break;
        firstChildIndex = (parentIndex * 2) + 1;
        secondChildIndex = (parentIndex * 2) + 2;
    }
    return returnValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;

    insertHeap(v);

    deleteMax(v);

    for (auto value : v)
        cout << value << " ";

    return 0;
}