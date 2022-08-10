//**** Check whether a Array is sorted (using Recursion)

#include <iostream>
using namespace std;
bool sort(int arr[], int n)
{
    if (n == 1) // When recursion applied-> As the length decrease to 1
    {
        // A sureshot condition for sorted array
        return 1;
    }

    return (arr[0] < arr[1] && sort(arr + 1, n - 1));
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(arr) / sizeof(int);

    cout << sort(arr, n) << endl;

    return 0;
}