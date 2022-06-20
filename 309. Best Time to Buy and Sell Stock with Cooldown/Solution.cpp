#include <bits/stdc++.h>
using namespace std;


// Runtime: 3 ms, faster than 89.96% of C++ 
// Memory Usage: 11.1 MB, less than 88.43% of C++ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sold[n+1];
        int held[n+1];
        int reset[n+1];
        reset[0] = 0;
        sold[0] = INT_MIN;
        held[0] = INT_MIN;

        for(int i = 1; i <= n; i++){
            reset[i] = max(reset[i-1], sold[i-1]);
            sold[i] = held[i-1] + prices[i-1];
            held[i] = max(held[i-1], reset[i-1] - prices[i-1]);
        }
        return max(sold[n], reset[n]);
    }
};