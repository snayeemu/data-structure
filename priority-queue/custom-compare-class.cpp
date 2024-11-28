#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int id, marks;
    Student(string name, int id, int marks)
    {
        this->name = name;
        this->id = id;
        this->marks = marks;
    }
};

class compare
{
public:
    bool operator()(Student a, Student b)
    {
        return a.marks > b.marks || (a.marks == b.marks && a.id > b.id);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, compare> pq;

    for (int i = 0; i < n; i++)
    {
        string name;
        int id, marks;
        cin >> name >> id >> marks;
        Student s(name, id, marks);
        pq.push(s);
    }

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().id << " " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}