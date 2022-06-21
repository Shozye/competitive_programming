#include <bits/stdc++.h>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++
// Memory Usage: 6.9 MB, less than 98.82% of C++
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount+1];

        dp[0] = 1;
        for(int i = 1; i <= amount; i++){
            dp[i] = 0;
        }

        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                dp[i] = dp[i] + dp[i-coin];
            }
        }
        
        return dp[amount];
    }
};