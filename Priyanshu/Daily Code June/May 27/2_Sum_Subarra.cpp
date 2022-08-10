#include <iostream>
using namespace std;
int main()
{
    int A[] = {12, 39, 38, 28, 19};
    int n = sizeof(A) / sizeof(int);

    int result = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {   

        for (int j = 1; j < n; j++)
        {
            sum += A[j];
            result +=sum;
        }
    }
    cout<<result<<endl;
    return 0;
}