// Code made by Priyanshu

#include <iostream>
#include <algorithm>
using namespace std;
void maxarray(int arr[], int n)
{
    int mx = -1999999;

    for (int i = 0; i < n; i++)
    {

        if (mx < arr[i])
        {
            mx = arr[i];
        }

        cout << mx << " ";
    }
}
int main()
{
    int A[] = {12, 38, 78, 29, 291};
    int n = sizeof(A) / sizeof(int);
    maxarray(A, n);
    return 0;
}