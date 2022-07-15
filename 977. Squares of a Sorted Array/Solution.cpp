#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int low, int high){
        if (high > low){
            int mid = (low + high) / 2;

            if (nums[mid] >= 0)
                return binary_search(nums, low, mid);
            return binary_search(nums, mid+1, high);
        }
        return low;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        int positive_min = binary_search(nums, 0, nums.size()-1);
        int negative_min = positive_min - 1;

        vector<int> sorted_squared;
        while (negative_min != -1 && positive_min != nums.size()){
            if (nums[positive_min] + nums[negative_min] > 0){
                sorted_squared.push_back(nums[negative_min]*nums[negative_min]);
                negative_min--;
            }
            else{
                sorted_squared.push_back(nums[positive_min]*nums[positive_min]);
                positive_min++;
            }
        }
        while (negative_min != -1){
            sorted_squared.push_back(nums[negative_min]*nums[negative_min]);
            negative_min--;
        }
        while (positive_min != nums.size()){
            sorted_squared.push_back(nums[positive_min]*nums[positive_min]);
            positive_min++;
        }
        return sorted_squared;
    }
};