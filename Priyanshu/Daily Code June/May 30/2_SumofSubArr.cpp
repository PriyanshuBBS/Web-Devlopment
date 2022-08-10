#include <iostream>
using namespace std;
int main()
{
    vector<int> subarraySum(int arr[], int n, long long s)
    {

        vector<int> res;
        int i = 0;
        int j = 1;
        if (arr[i] == s)
        {
            res.push_back(i + 1);
            res.push_back(i + 1);
            return res;
        }

        int sum = arr[0];
        while (i < n && j <= n)
        {
            // sum=sum+arr[j];
            if (sum == s)
            {
                res.push_back(i + 1);
                res.push_back(j);
                break;
            }
            else if (arr[j] + sum <= s)
            {
                sum = sum + arr[j]; // Forward Values are addded
                j++;
            }
            else
            {
                sum = sum - arr[i]; // The value from start is removed;
                i++;
            }
        }
        if (sum == s)
        {

            return res;
        }
        else
        {
            res.push_back(-1);
            return res;
        }
    }

    return 0;
}