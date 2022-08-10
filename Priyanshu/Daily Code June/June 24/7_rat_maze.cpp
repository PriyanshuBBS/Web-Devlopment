#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n) // x and y are coordinate & n is size of array
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratmaze(int **arr, int x, int y, int n, int **res)
{
    // The base condition

    if (x == n - 1 && y == n - 1)
    {
        res[x][y] = 1;
        return true; // Reached the final location
    }

    if (isSafe(arr, x, y, n))
    {
        res[x][y] = 1; // Making that postn reacheable by rat

        if (ratmaze(arr, x + 1, y, n, res)) // Moving towards right
        {
            return true;
        }

        if (ratmaze(arr, x, y + 1, n, res)) // Moving towards down
        {
            return true;
        }

        // If both above statement not implemented, then we are choosing wrong path
        // and need to go back i.e., make that postn not reachable by rat

        res[x][y] = 0; // Backtracked
        return false;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n]; // Declare a memory block of size m*n

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;

    int **res = new int *[n];

    for (int i = 0; i < n; i++)
    {
        res[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
        }
    }

    if (ratmaze(arr, 0, 0, n, res))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}