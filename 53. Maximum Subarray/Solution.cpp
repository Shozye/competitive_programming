#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n], r, best_dp;
        // dp[i] is value of sum of best contigious subarray with right end i
        // recurrence relation: dp[i] = max(dp[i-1] + nums[i], nums[i]);
        // We can either join nums[i] with previous contigious or leave alone

        dp[0] = nums[0];
        best_dp = dp[0];
        for(int r = 1; r < n; r++){
            dp[r] = max(dp[r-1] + nums[r], nums[r]);
            best_dp = max(dp[r], best_dp);
        }

        return best_dp;
    }
};