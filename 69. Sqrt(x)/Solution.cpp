#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long l = 0; long long r = min(x, 1000000);
        long long mid;
        long long pow;
        while(l +1 < r){
            mid = l + (r-l)/2;

            pow = mid*mid;
            if(pow <= x){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        if (r*r <= x){
            return r;
        }
        return l;
    }
};