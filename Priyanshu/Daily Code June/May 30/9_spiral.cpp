#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int r_start = 0, r_end = n - 1, c_start = 0, c_end = m - 1;

    while (r_start <= r_end && c_start <= c_end)
    {
        for (int i = c_start; i <= c_end; i++)
        {
            cout<<arr[r_start][i]<<" ";
        }
        r_start ++;

        for (int j = row_start; j <= row_end; j++)
        {
            cout<<arr[j][c_end]<<" ";
        }
        c_end--;

        for (int i = c_end; i >= c_start; i--)
        {
            cout<<arr[r_end][i]<<" ";
        }
        r_end--;
        
        for (int j = r_end; j >=r_start; j++)
        {
            cout<<arr[j][c_start];
        }

        c_start --;
        
        
    }

    return 0;
}