#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int setBits(int N) {
        
        int count=0; 
        
        while(N){
        N = (N & N-1); // Make only rightmost  bit(1) = 0
        count++;
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
 