#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int goal;
    bool can_make_square(int l, int r, int t, int b, vector<int>& matchsticks, int index){
        if (index >= matchsticks.size()){
            return (l == r && r == t && t == b);
        }
        int current = matchsticks[index];
        if (l + current <= goal){
            if (can_make_square(l + current, r, t, b, matchsticks, index + 1)){
                return true;
            }
        }
        if (r + current <= goal){
            if (can_make_square(l, r + current, t, b, matchsticks, index + 1)){
                return true;
            }
        }
        if (t + current <= goal){
            if (can_make_square(l, r, t + current, b, matchsticks, index + 1)){
                return true;
            }
        }
        if (b + current <= goal){
            if (can_make_square(l, r, t, b + current, matchsticks, index + 1)){
                return true;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int stick: matchsticks){
            sum += stick;
        }
        if (sum % 4 != 0){
            return false;
        }
        goal = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return can_make_square(0,0,0,0, matchsticks, 0);
    }
};