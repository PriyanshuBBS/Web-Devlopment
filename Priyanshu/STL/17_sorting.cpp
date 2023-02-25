/* Sorting in STL is best in class
Introsort - It is a mix of 3 algo (Quick, Heap & Insertion)
and is called best algo for sorting

Proper Def:  a hybrid sorting algorithm that provides both
fast average performance and (asymptotically) optimal worst-case performance.

Comparator Function : Used to define custom behaviour in sorting
*/

#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // sort the intervals in increasing order of start time
    sort(arr, arr + n, compareInterval);

    cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
             << "] ";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // --> Any sorting, uses comparisions and on that we get the behavious of sorting
            // if(a[i] < a[j])
            // if (cmp(arr[i], arr[j]))
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    return 0;
}