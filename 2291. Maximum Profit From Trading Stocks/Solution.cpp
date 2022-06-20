#include <bits/stdc++.h>
using namespace std;

// Runtime: 182 ms, faster than 87.01% of C++ 
// Memory Usage: 16.2 MB, less than 64.96% of C++ 
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        int knapsack[n+1][budget+1];
        for(int i = 0; i <= budget; i++){
            knapsack[0][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j=0; j <= budget; j++){
                if(j - present[i-1] >= 0){
                    knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-present[i-1]] + future[i-1] - present[i-1]);
                }
                else{
                    knapsack[i][j] = knapsack[i-1][j];
                }
            }
        }
        return knapsack[n][budget];
    }
};