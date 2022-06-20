#include <bits/stdc++.h>
using namespace std;

// Runtime: 7 ms, faster than 81.02% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.1 MB, less than 53.20% of C++ online submissions for Best Time to Buy and Sell Stock II.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int possible_profit;
        for(int i = 0 ; i < prices.size()-1; i++){
            possible_profit = prices[i+1] - prices[i];
            if(possible_profit > 0){
                profit += possible_profit;
            } 
        }
        return profit;
    }
};