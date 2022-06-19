#include <bits/stdc++.h>
using namespace std;

// Runtime: 226 ms, faster than 23.54% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.4 MB, less than 52.07% of C++ online submissions for Best Time to Buy and Sell Stock.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest, maxprofit;
        cheapest = prices[0];
        maxprofit = 0;
        for(int i = 1; i < prices.size(); i++){
            maxprofit = max(maxprofit, prices[i]-cheapest);
            cheapest = min(cheapest, prices[i]);
        }
        return maxprofit;
    }
};