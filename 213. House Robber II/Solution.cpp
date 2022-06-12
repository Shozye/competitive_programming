#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob_basic(vector<int> nums){
        int n = nums.size();
        if(n==0)
            return 0;
        
        if (n==1)
            return nums[0];
        
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int last = nums[n-1];

        nums.pop_back();
        int without_last = rob_basic(nums);
        nums.push_back(last);
        nums.erase(nums.begin());
        int without_first = rob_basic(nums);
        return max(without_first, without_last);
    }
};