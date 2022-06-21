#include <bits/stdc++.h>
using namespace std;

// Difference between this solution and previous is using binary_search
class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right, int x){
        
        if (left >= right){
            return left;
        }
        int mid = (left+right)/2;
        if(nums[mid] == x){
            return mid;
        }
        if(nums[mid] < x){
            return binary_search(nums, mid+1, right, x);
        }
        return binary_search(nums, left, mid, x);
        

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequence;
        subsequence.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];

            if (num > subsequence.back()){
                subsequence.push_back(num);
                continue;
            }
            int place = binary_search(subsequence, 0, subsequence.size()-1, num);
            subsequence[place] = num;
            
        }
        return subsequence.size();
    }
};