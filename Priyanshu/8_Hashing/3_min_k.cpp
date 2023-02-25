// Sliding Window

#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,k;
    cin>>n>>k;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    int sum = 0, ans = INT_MAX;

    // For 1st window
    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }

    ans = min(ans,sum);

    // Sliding Window
    for (int i = 1; i < n-k+1; i++) // n-k + 1 (condition excludes the 1st windows)
    {
        sum -= a[i-1];
        sum += a[i+k-1];
        ans = min(ans,sum);
    }

    cout<<ans<<endl;
    
    return 0;
}