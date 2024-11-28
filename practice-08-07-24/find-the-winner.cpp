#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        int numberOfPeople = n, peopleToBeRemoved = k;
        queue<int> queOfPeoples;

        for (int i = 1; i <= numberOfPeople; i++)
            queOfPeoples.push(i);

        int count = 0;

        while (queOfPeoples.size() > 1)
        {
            count++;
            int person = queOfPeoples.front();
            queOfPeoples.pop();
            
            if (count % peopleToBeRemoved != 0)
                queOfPeoples.push(person);
            
        }

        return queOfPeoples.front();
    }
};

int main()
{
    Solution sl;

    cout << (sl.findTheWinner(5, 2));

    return 0;
}