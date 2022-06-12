#include <bits/stdc++.h>
using namespace std;

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