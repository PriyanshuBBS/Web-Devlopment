#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};

    int n = sizeof(arr) / sizeof(int);

    // By default sorting - i.e, in asending order
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // Desecending order with the help of gretaer function
    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}