#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0; // base case
        }
        int dp[n];
        int new_reach;
        dp[0] = 0;
        int reach = 0;
        for(int i = 0; i < n; i++){
            if (i + nums[i] >= n-1){
                dp[n-1] = dp[i]+1;
                break;
            }
            if(i + nums[i] > reach){
                new_reach = i + nums[i];
                for(int j = reach+1; j <= new_reach; j++){
                    dp[j] = dp[i] + 1;
                }
                reach = new_reach;
            }
        }
        return dp[n-1]; 
    }
};