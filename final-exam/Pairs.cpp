#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int id;
    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }
};

class compare
{
public:
    bool operator()(Person p1, Person p2)
    {
        return p1.name > p2.name || (p1.name == p2.name && p1.id < p2.id);
    }
};

bool compare(Person p1, Person p2)
{
    return p1.name < p2.name || (p1.name == p2.name && p1.id > p2.id);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Person> persons;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int id;
        cin >> name >> id;
        Person p(name, id);
        persons.push_back(p);
    }

    sort(persons.begin(), persons.end(), compare);

    // while (!persons.empty())
    // {
    //     cout << persons.top().name << " " << persons.top().id << endl;
    //     persons.pop();
    // }

    for (auto person : persons)
        cout << person.name << " " << person.id << endl;

    return 0;
}