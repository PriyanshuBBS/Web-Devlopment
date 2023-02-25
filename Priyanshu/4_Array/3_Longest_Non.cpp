//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        vector<int> dict(256, -1); // 256 space all having value -1
        int maxLen = 0, start = -1;
        // #1
        for (int i = 0; i < S.size(); i++)
        {
            if (dict[S[i]] > start) // Did the postn of that alphabet is > than the prev occurence of same alphabet
                start = dict[S[i]]; //#2

            dict[S[i]] = i; // Marking the postn in Dict vector
            // # 3
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};