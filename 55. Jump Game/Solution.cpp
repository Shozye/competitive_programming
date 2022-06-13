#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];

        dp[0] = true;
        for(int i = 1 ; i < n ; i++){
            dp[i] = false;
        }
        for(int i = 0; i < n; i++){
            if(dp[i] == true && (i+nums[i]) >= n){
                return true;
            }
            if (dp[i] == true)
                for(int k = 0; k <= nums[i]; k++)
                    dp[i+k] = true;
        }
        return dp[n-1];
    }
};