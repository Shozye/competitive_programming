#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int amount_1 = 0;
        while (n != 0){
            if (n%2 == 1){
                amount_1 += 1;
            }
            n /= 2;
        }
        return amount_1;
    }
};