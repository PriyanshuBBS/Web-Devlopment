#include <iostream>
using namespace std;
int main()
{
    int a[5] = {43, 89, 67, 45, 86};

    for (int i = 1; i < 5; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (a[j] > temp && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
    return 0;
}


