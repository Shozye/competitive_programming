#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // dp[i][j] is answer to the problem if text1 start from it's i-th index and text2 starts from it's j-th index
        int dp[n+1][m+1];
        // Base cases: If one of them is empty then answer is 0
        for(int i = 0; i < n+1; i++){
            dp[i][m] = 0;
        }
        for(int i = 0; i < m+1; i++){
            dp[n][i] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for (int j = m-1; j >= 0; j--){

                // This is reccurence relation
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
                // end of reccurence relation

            }
        }
        // dp[0][0] is answer to original problem
        return dp[0][0];
    }
};