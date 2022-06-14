#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int biggest_num = 0;
        int dp[n][m];
        for(int i = 0; i < n; i++){
            dp[i][0] = matrix[i][0] - 48;
            biggest_num = max(dp[i][0], biggest_num);
        }
        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i] - 48;
            biggest_num = max(dp[0][i], biggest_num);
        }


        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if (matrix[i][j] - 48 == 1){
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    if (dp[i][j] > biggest_num)
                        biggest_num = dp[i][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        return biggest_num*biggest_num;
    }
};