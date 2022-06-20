#include <bits/stdc++.h>
using namespace std;

// Runtime: 170 ms, faster than 58.39% of C++ 
// Memory Usage: 54.9 MB, less than 89.96% of C++ 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int held, prev_held;
        int reset, prev_reset;
        
        prev_reset = 0;
        prev_held = INT_MIN + fee;

        for(int i = 1; i <= n; i++){
            held = max(prev_reset - prices[i-1], prev_held);
            reset = max(prev_reset, prev_held + prices[i-1] - fee);

            prev_reset = reset;
            prev_held = held;
        }
        return reset;
    }
};