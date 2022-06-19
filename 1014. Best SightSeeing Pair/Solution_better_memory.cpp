#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int best_ends[n];
        int ends[n];
        int starts[n];

        best_ends[n-1] = values.back() - n + 1;
        for(int i = n-2; i >= 0; i--){
            best_ends[i] = max(best_ends[i+1], values[i] - i);
        }
        int res = 0;
        for(int i = 0; i < n-1; i++){
            res = max(res, values[i] + i + best_ends[i+1]);
        }
        return res;
    }
}; 