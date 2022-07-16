#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    int m;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int grid[m][n];
        int helpergrid[m][n];
        int max_int = 1000000007;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = 0;
                helpergrid[i][j] = 0;
            }
        }
        grid[startRow][startColumn] = 1;
    

        int out_of_bounds_counter = 0;
        for(int move=1; move <= maxMove; move++){
            
            for(int row = 0; row < m; row++){
                out_of_bounds_counter = (out_of_bounds_counter + grid[row][0])%max_int;
                out_of_bounds_counter = (out_of_bounds_counter + grid[row][n-1])%max_int;
            }
            for(int col = 0; col < n; col++){
                out_of_bounds_counter = (out_of_bounds_counter + grid[m-1][col])%max_int;
                out_of_bounds_counter = (out_of_bounds_counter + grid[0][col])%max_int;
            }
            
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if (i > 0){
                        helpergrid[i][j] = (helpergrid[i][j] + grid[i-1][j])%max_int;
                    }
                    if ( i < m - 1){
                        helpergrid[i][j] = (helpergrid[i][j] + grid[i+1][j])%max_int;
                    }
                    if(j > 0){
                        helpergrid[i][j] = (helpergrid[i][j] + grid[i][j-1])%max_int;
                    }
                    if( j < n - 1){
                        helpergrid[i][j] = (helpergrid[i][j] + grid[i][j+1])%max_int;
                    }
                }
            }

            
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    grid[i][j] = helpergrid[i][j];
                    helpergrid[i][j] = 0;
                }
            }
        }
        return out_of_bounds_counter;
    }
};