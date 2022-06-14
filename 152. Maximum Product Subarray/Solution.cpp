#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int curr_product = 1;
        for(int i = 0; i < nums.size(); i++){
            curr_product *= nums[i];
            max_product = max(curr_product, max_product);
            if (curr_product == 0){
                curr_product = 1;
            }
        }
        
        curr_product = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            curr_product *= nums[i];
            max_product = max(curr_product, max_product);
            if (curr_product == 0){
                curr_product = 1;
            }
        }
        return max_product;
    }
};