#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_length = 1;
        int prev_longest = 1;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i-1] < nums[i]){
                prev_longest += 1;
            }
            else{
                if (max_length < prev_longest)
                    max_length = prev_longest;
                prev_longest = 1;
            }
        }
        if (max_length < prev_longest)
            max_length = prev_longest;
        return max_length;
    }
};