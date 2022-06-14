#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        int dp[n][d+1];
        if (n < d)
            return -1;

        dp[n-1][d] = jobDifficulty[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i][d] = max(dp[i+1][d], jobDifficulty[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < d; j++){
                dp[i][j] = -1;
            }
        }

        for(int day = d-1; day > 0; day--){
            for(int i = n-2; i >= 0; i--){
                if(n - day < 0){
                    dp[i][day] = -1;
                } 
                else{
                    int hardest = jobDifficulty[i];
                    int min_possible = hardest + dp[i+1][day+1];
                    for(int j = i+1; j < n - (d - day); j++){
                        hardest = max(jobDifficulty[j], hardest);
                        min_possible = min(min_possible, hardest + dp[j+1][day+1]);
                    }
                    dp[i][day] = min_possible;
                }
            }
        }
        
        return dp[0][1];
        
    }
};