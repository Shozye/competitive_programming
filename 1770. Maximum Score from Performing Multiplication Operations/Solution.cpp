#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int maximumScore(vector<int>& nums, vector<int>& multipliers){
        int m, n, mult, right;
        m = multipliers.size();
        n = nums.size();
        int dp[m+1][m+1];

        for(int i = 0; i <= m; i++)
            dp[m][i] = 0;

        for(int i = m-1; i >= 0; i--){
            mult = multipliers[i];
            for(int left = 0; left <= i; left ++){
                right = n - 1 - (i - left);
                dp[i][left] = max(
                                ( nums[right]*mult + dp[i+1][left  ] )
                               ,( nums[left ]*mult + dp[i+1][left+1] )
                               );
            }
        }
        return dp[0][0];
    }
};