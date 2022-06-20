#include <bits/stdc++.h>
using namespace std;

// Runtime: 3 ms, faster than 97.85% of C++
// Memory Usage: 8.5 MB, less than 88.49% of C++ 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                cout << i << " " << j << endl;
                if (j-1 >= 0 && j <= i-1){
                    triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
                }
                else if (j-1 >= 0){
                    triangle[i][j] =  triangle[i-1][j-1]+ triangle[i][j];
                }
                else if (j <= i-1){
                    triangle[i][j] =  triangle[i-1][j] + triangle[i][j];
                }
            }
        }

        int ret = INT_MAX;
        for(int i = 0; i < n; i++){
            if (triangle[n-1][i] < ret){
                ret = triangle[n-1][i];
            }
        }
        return ret;
    }
};