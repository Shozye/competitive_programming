#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = 1;

        for(int i = 1; i < nums.size(); i++){
            int maxx = 0;
            for(int j = 0; j < i; j++){
                if (nums[j] < nums[i] && dp[j] > maxx){
                    maxx = dp[j];
                }
            }
            dp[i] = maxx + 1;
        }
        
        int ret = 0;
        for(int i = 0; i < nums.size(); i++){
            if (dp[i] > ret){
                ret = dp[i];
            }
        }
        return ret;
    }
};