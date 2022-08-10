// *** Find the unique number in an array occuring only once

#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int arr[], int n)
{
    // Taking XOR of array -> which at end will give XOR(two unique number too)
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }
    int tempxor = xorsum;   // This include XOR of 2 unique numbers too

    // Finding the position where right most setbit is present
    int setbit = 0;
    int pos = 0;
    while (setbit != 1) // As soon we get setbit 1 loop breaks
    {
        setbit = xorsum & 1; // Set bit = right most set bit as & gives 1 only with 1
        pos++;
        xorsum = xorsum >> 1;
    }

    // Taking XOR of element having setbit  equal to the of  position right most  (pos)
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos - 1)) // if(arr[i] have 1)
        {
            newxor ^= arr[i];
        }
    }
    cout << newxor << endl; // first  unique number
    cout << (tempxor ^ newxor) << endl;
}

int main()
{
    int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
    int n = sizeof(arr) / sizeof(int);

    unique(arr, n);
    return 0;
}