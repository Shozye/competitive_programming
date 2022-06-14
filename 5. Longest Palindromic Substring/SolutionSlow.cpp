#include <bits/stdc++.h>
using namespace std;

// Runtime: 52 ms, 66.10%
// Memory Usage: 8.1 MB, 68.27%
class Solution {
public:
    string longestPalindrome(string s) {
        string T;
        int n = s.size();
        T.push_back('|');
        for(int i = 0; i < n; i++){
            T.push_back(s.at(i));
            T.push_back('|');
        }

        int radiuses[2*n + 1];

        for(int i = 0; i < 2*n+1; i++){
            int radius = 0;
            while(i-radius >= 0 && i + radius < 2*n+1 && T[i-radius] == T[i+radius]){
                radiuses[i] = radius;
                radius++;
            }
        }
        int best_i = 0;
        int max_radius = 0;
        for(int i = 0; i < 2*n+1; i++){
            if (max_radius < radiuses[i]){
                max_radius = radiuses[i];
                best_i = i;
            }
        }
        
        string answer;
        
        for(int i = best_i - max_radius; i <= best_i + max_radius; i++){
            if (i % 2 == 1){
                answer.push_back(T[i]);
            }
        }
        
        return answer;
    }
};