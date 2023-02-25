#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
    //Function to find if there exists a triplet in the array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        bool triplet = false;
        
        // O(n log n)
       sort(A,A + n);
        
        // O(n^2)
        for(int i = 0; i<n ;i++){
            int lo = i+1, hi = n-1;
            while(lo<hi){
                int current = A[i] + A[lo] + A[hi];
                if(current == X){
                    triplet = true;
                }
                if(current < X){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        return triplet;
    }

};