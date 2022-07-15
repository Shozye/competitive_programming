#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;

        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    vector<int> stacki;
                    vector<int> stackj;
                    stacki.push_back(i);
                    stackj.push_back(j);
                    int size = 0;
                    grid[i][j] = 0;
                    while (!stacki.empty()){
                        int i = stacki.back();
                        int j = stackj.back();
                        stacki.pop_back();
                        stackj.pop_back();
                        size++;

                        if (i > 0){
                            if (grid[i-1][j] == 1){
                                stacki.push_back(i-1);
                                stackj.push_back(j);
                                grid[i-1][j] = 0;
                            }
                        }
                        if (i < n-1){
                            if (grid[i+1][j] == 1){
                                stacki.push_back(i+1);
                                stackj.push_back(j);
                                grid[i+1][j] = 0;
                            }
                        }
                        if (j > 0){
                            if (grid[i][j-1] == 1){
                                stacki.push_back(i);
                                stackj.push_back(j-1);
                                grid[i][j-1] = 0;
        
                            }
                        }
                        if (j < m-1){
                            if (grid[i][j+1] == 1){
                                stacki.push_back(i);
                                stackj.push_back(j+1);
                                grid[i][j+1] = 0;
                            }
                        }                        
                    }
                    if (size > max_size){
                        max_size = size;
                    }
                }
            }
        }
        return max_size;
    }
};