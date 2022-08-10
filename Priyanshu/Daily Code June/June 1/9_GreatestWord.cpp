#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int counter = 0, maxlen = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            counter = 0;
        }
        else
        {
            counter++;
        }
        maxlen = max(maxlen, counter);
    }

    cout << maxlen << endl;

    // while (1)
    // {
    //     if (arr[i] == ' ' || arr[i] == '\0')
    //     {
    //         if (currLen > maxlen)
    //         {
    //             maxlen = currLen;
    //         }

    //         currLen = 0;
    //     }
    //     else
    //         currLen++;
    //     if (arr[i] == '\0')
    //         break;

    //     i++;
    // }

    // cout << maxlen << endl;
    return 0;
}
