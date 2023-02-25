#include <iostream>
using namespace std;

int Binary_Search(int arr[], int n, int k)
{
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }

        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int A[] = {12, 378, 67, 378, 57, 928};
    int n = sizeof(A) / sizeof(int);

    cout << "Enter the element to find";
    int element;
    cin >> element;

    cout << "The Element " << element << " found at " << Binary_Search(A, n, element) << endl;
    return 0;
}