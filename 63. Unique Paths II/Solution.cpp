#include <bits/stdc++.h>
using namespace std;


// Runtime: 2 ms, faster than 84.73% of C++
// Memory Usage: 7.5 MB, less than 98.35% of C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        bool found_obstacle;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1){
            return 0;
        }

        obstacleGrid[0][0] = 1;
        found_obstacle = false;
        for(int i = 1; i < n; i++){
            if (found_obstacle){
                obstacleGrid[i][0] = 0;
            }
            else if (obstacleGrid[i][0] == 1){
                found_obstacle = true;
                obstacleGrid[i][0] = 0;
            }
            else{
                obstacleGrid[i][0] = 1;
            }
        }
        found_obstacle = false;
        // here we start 
        for(int i = 1; i < m; i++){
            if (found_obstacle){
                obstacleGrid[0][i] = 0;
            }
            else if (obstacleGrid[0][i] == 1){
                found_obstacle = true;
                obstacleGrid[0][i] = 0;
            }
            else{
                obstacleGrid[0][i] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1 ; j < m; j++){
                if (obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                }
                else{
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[n-1][m-1];
    }
};