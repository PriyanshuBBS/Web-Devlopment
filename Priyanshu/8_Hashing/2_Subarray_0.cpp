// A C++ program to find if there is a zero sum subarray
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool subArrayExists(int arr[], int n)
    {
       unordered_set <int> s;
       int pre_sum = 0;
       for(int i = 0; i < n ; i++)
       {
           pre_sum += arr[i];
           
           if(pre_sum == 0)
                return true;
           if(s.find(pre_sum) != s.end())
                return true;
           s.insert(pre_sum);
       }
       return false;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}