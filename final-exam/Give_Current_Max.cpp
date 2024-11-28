#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll, marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class compare
{
public:
    bool operator()(Student s1, Student s2)
    {
        return s1.marks < s2.marks || (s1.marks == s2.marks && s1.roll > s2.roll);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<Student, vector<Student>, compare> students;

    while (n--)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student s(name, roll, marks);
        students.push(s);
    }

    int numberOfQueries;
    cin >> numberOfQueries;

    while (numberOfQueries--)
    {
        int query;
        cin >> query;
        if (query == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student s(name, roll, marks);
            students.push(s);
            Student current = students.top();
            cout << current.name << " " << current.roll << " " << current.marks << endl;
        }
        else if (query == 1)
        {
            if (!students.empty())
            {
                Student current = students.top();
                cout << current.name << " " << current.roll << " " << current.marks << endl;
            }
            else
                cout << "Empty" << endl;
        }
        else if (query == 2)
        {
            if (!students.empty())
            {
                students.pop();
                Student current = students.top();
                if (!students.empty())
                    cout << current.name << " " << current.roll << " " << current.marks << endl;
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
    }

    return 0;
}