#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 2*10000 + 1;
        int counters[n], dp[n];
        
        // Fill Counter with ones 
        for(int i = 0; i < n; i++)
            counters[i] = 0;
        
        for(int i = 0; i < nums.size(); i++)
            counters[nums[i]]++;
        
        dp[0] = counters[0] * 0;
        dp[1] = counters[1] * 1;
        dp[2] = counters[2] * 2;
        
        if (n <= 2)
            return dp[n];
        
        for(int i = 3; i < n; i++){
            dp[i] = max(dp[i-3] + counters[i]*i, dp[i-2] + counters[i]*i); 
        }
        return max(dp[n-2], dp[n-1]);
    }
};