/*Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is
 Vi. A day is record breaking if it satisfies both of the following conditions:

The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.
*/


#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    // a[n] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    int rb_day = 0;
    int mx = -1;        // Setting the value before start of comparions (Since all n ar +ve hence -1 )

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx && a[i] > a[i + 1])
        {
            rb_day++;
        }
        mx = max(mx, a[i]);
    }

    cout << rb_day << endl;
    return 0;
}