#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1], smallest;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
            dp[i] = INT_MAX;
        
        for(int i = 1; i <= amount; i++){
            for(auto coin: coins){
                if(i-coin >= 0 && dp[i-coin] != INT_MAX){
                    dp[i] = min(dp[i-coin] + 1, dp[i]);
                }
            }
        }
        
        if (dp[amount] == INT_MAX)
            return -1;    
        return dp[amount];
    }
};