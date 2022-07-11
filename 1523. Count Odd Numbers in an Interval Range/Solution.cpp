#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        if (high - low == 0){
            if (low%2 == 0){
                return 0;
            }
            return 1;
        }
        if (high - low == 1){
            return 1;
        }
        int am_nums = high - low + 1;
        if (low%2 == 0){
            am_nums -= 1;
        }
        if (high%2 == 0){
            am_nums -= 1;
        }
        return am_nums/2 + 1;
        
    }
};