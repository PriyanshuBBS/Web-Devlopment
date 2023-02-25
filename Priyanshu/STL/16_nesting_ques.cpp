// Monk and marks problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // multi sets are used since there can be 2 student with same number and name
    map<int, multiset<string>> marks_map;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;

        marks_map[marks].insert(name);
    }

    // Marks are needed in decreasing order, so we need to reverse iterate the map
    auto cur_it = --marks_map.end();

    // Putting a infinte loop
    while (true)
    {
        auto &students = (*cur_it).second;
        int marks = (*cur_it).first;

        for (auto student : students)
        {
            cout << student << " " << marks << endl;
        }


        if (cur_it == marks_map.begin())
            break;

        cur_it--;
    }

    // --------> To decrease the reverse iterate
    /*
    We can insert -value in map
    marks_map[-1 * marks].insert(name);

    and multiply -1 at the time of printing
   
    for(auto & marks_students_pr : marks_map){
        auto &students = marks_students_pr.second;
        int marks = marks_students_pr.first;
        for(auto student : students){
            cout<< student <<" "<<-1* marks;
        }
    }

    */
}