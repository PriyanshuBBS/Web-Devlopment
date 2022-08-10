// Print all the subset of array using BIT Manipulation

#include <iostream>
using namespace std;
void subset(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++) // Traverse through list of subset (top - bottom)
    {
        for (int j = 0; j < n; j++) // Trave through each sub set
        {
            if (i & 1 << j) // Checking if set bit exist at where i.e.,if  set bit at j=1, then print value at 1
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    subset(arr, n);
    return 0;
}