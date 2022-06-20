#include <bits/stdc++.h>
using namespace std;

// Runtime: 170 ms, faster than 58.39% of C++ 
// Memory Usage: 55.4 MB, less than 57.56% of C++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int held[n+1];
        int reset[n+1];
        
        reset[0] = 0;
        held[0] = INT_MIN + fee;

        for(int i = 1; i <= n; i++){
            held[i] = max(reset[i-1] - prices[i-1], held[i-1]);
            reset[i] = max(reset[i-1], held[i-1] + prices[i-1] - fee);
        }
        return reset[n];
    }
};