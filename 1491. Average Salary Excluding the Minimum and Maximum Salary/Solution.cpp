#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int min = INT_MAX;
        int max = 0;
        int sum = 0;
        for(int s: salary){
            if (s < min){
                min = s;
            }
            if (s > max){
                max = s;
            }
            sum += s;
        }
        return (sum - min - max) / (salary.size()-2);
    }
};