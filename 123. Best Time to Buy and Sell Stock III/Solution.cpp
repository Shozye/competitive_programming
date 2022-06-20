#include <bits/stdc++.h>
using namespace std;

// Runtime: 165 ms, faster than 90.38% of C++
// Memory Usage: 77.2 MB, less than 66.77% of C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int reset_2_sell[n+1];
        int held__2_sell[n+1];
        int reset_1_sell[n+1];
        int held__1_sell[n+1];
        int reset_0_sell[n+1];

        int max_price = INT_MIN;
        for(int i = 0; i < n; i++){
            max_price = max(max_price, prices[i]);
        }
        
        reset_2_sell[0] = 0;
        held__2_sell[0] = INT_MIN + max_price;
        reset_1_sell[0] = INT_MIN + max_price;
        held__1_sell[0] = INT_MIN + max_price;
        reset_0_sell[0] = INT_MIN + max_price;

        for(int i = 1; i <= n; i++){
            reset_2_sell[i] = 0;
            held__2_sell[i] = max(held__2_sell[i-1], reset_2_sell[i-1] - prices[i-1]);
            reset_1_sell[i] = max(reset_1_sell[i-1], held__2_sell[i-1] + prices[i-1]);
            held__1_sell[i] = max(held__1_sell[i-1], reset_1_sell[i-1] - prices[i-1]);
            reset_0_sell[i] = max(reset_0_sell[i-1], held__1_sell[i-1] + prices[i-1]);
        }
        int best_reset = max(max(reset_0_sell[n], reset_1_sell[n]), reset_2_sell[n]);
        return best_reset;
    }
};