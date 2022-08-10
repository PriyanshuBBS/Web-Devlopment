/* Theory of Sub Arithmatic Array
 Ar. Subarray

10	7	4	6	8	10	11

pd -> measure the difference between last two digits of array
current -> measeure the length till which difference is same.
result -> It saves the value of lenght(current) when it is updated to 2, if the difference
    between digits not became same.

pd = It is set before for comparisons
*/

#include <iostream>
using namespace std;
int main()
{
    int a[] = {10, 7, 4, 6, 8, 10, 11}, n = sizeof(a) / sizeof(int);

    int pd = a[1] - a[0];
    int current = 2; // Both variables are = 2,as there are 2 variables having same diff. or 1 value of difference
    int max_length = 2;

    for (int j = 2; j < n; j++)
    {
        if (pd == a[j] - a[j - 1])
        {
            current++; // If the difference between the current digits & previous is same, then the counter
        }              // caclulate the length in continuity is update by 1 . eg- if it is same then counter -> 3
        else
        {
            pd = a[j] - a[j - 1];
            current = 2; // If the difference not same/ the continuty breaks then the counter resets to 2.
        }
        max_length = max(max_length, current); // When the chain breaks, the value of current resets. And the previous
    }                                          // maximum value of longest chain destroyed to preserve this it is used.

    cout << max_length << endl;
    return 0;
}