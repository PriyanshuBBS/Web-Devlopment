// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
  public:
  bool getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}


int setBit(int n, int pos)
{
    return (n | (1 << pos));
}


    int findUnique(int a[], int n, int k) {
       int result = 0;


       // How to fill the 64 bit array? The 
    for (int i = 0; i < 64; i++)        // Traversing through the 64 bit array
    {
        int sum = 0;
        for (int j = 0; j < n; j++)     // Traverse (original array)
        {   
            // Checking the no. of elements have 1 at ith position
            
            if (getBit(a[j], i))     // if ( element has 1 at ith (eg 2))
            {
                sum++;
            }

        }

        // The number having triplet is a multiple of 3
        if (sum % k != 0)   // If the number is not multiple of 3, then it is the number
        {
            result = setBit(result, i);
        }
    }
    return result;
    }

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution obj;
        cout << obj.findUnique(a, n, k) << endl;
    }
}  // } Driver Code Ends