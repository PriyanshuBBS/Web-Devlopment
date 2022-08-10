#include <iostream>
using namespace std;

int foccu(int arr[], int n, int k, int i)
{

    if (i == n)
    {
        return -1;
    }

    if (arr[i] == k)
    {
        return i;
    }

    return foccu(arr, n, k, i + 1);
}

int loccu(int arr[], int n, int k, int i)
{
    if (i == n)
    {
        return -1;
    }

    
    int res = loccu(arr, n, k, i + 1);

    if (res != -1)
    {
        return res;
    }

    if (arr[i] == k)
    {
        return i;
    }

    return -1;
}

int main()
{

    return 0;
}