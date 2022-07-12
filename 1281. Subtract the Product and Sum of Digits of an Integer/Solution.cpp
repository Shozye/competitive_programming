#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        int digit;
        while (n != 0){
            digit = n%10;
            n/=10;

            product *= digit;
            sum += digit;
        }
        return product - sum;
    }
};