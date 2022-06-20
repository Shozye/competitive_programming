#include <bits/stdc++.h>
using namespace std;

// Runtime: 3 ms, faster than 89.96% of C++ 
// Memory Usage: 11.2 MB, less than 70.47% of C++ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sold, sold_prev;
        int held, held_prev;
        int reset, reset_prev;
        reset_prev = 0;
        sold_prev = INT_MIN;
        held_prev = INT_MIN;

        for(int i = 1; i <= n; i++){
            reset = max(reset_prev, sold_prev);
            sold = held_prev + prices[i-1];
            held = max(held_prev, reset_prev - prices[i-1]);

            reset_prev = reset;
            sold_prev = sold;
            held_prev = held;
        }
        return max(sold, reset);
    }
};