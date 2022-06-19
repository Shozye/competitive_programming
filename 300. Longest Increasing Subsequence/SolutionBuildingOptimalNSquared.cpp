#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequence;
        subsequence.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];

            if (num > subsequence.back()){
                subsequence.push_back(num);
                continue;
            }
            for(int j = subsequence.size()-1; j >= 0; j++){
                if (num < subsequence.at(j)){
                    subsequence[j] = num;
                    break;
                }
            }
        }
        return subsequence.size();
    }
};