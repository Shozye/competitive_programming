#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> subsequence;
        subsequence.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];

            if (num > subsequence.back()){
                subsequence.push_back(num);
                continue;
            }
            for(int j = 0; j < subsequence.size(); j++){
                
                if (num <= subsequence.at(j)){
                    subsequence[j] = num;
                    break;
                }
            }
        }
        return subsequence.size();
    }
};