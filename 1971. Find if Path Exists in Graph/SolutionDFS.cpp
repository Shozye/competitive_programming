#include <bits/stdc++.h>
using namespace std;

// Runtime: 1424 ms, faster than 10.74% of C++
// Memory Usage: 177.7 MB, less than 48.59% of C++

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int visited[n];
        
        vector<vector<int>> neighbourings;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            neighbourings.push_back(temp);
        }
        for(auto pair: edges){
            neighbourings[pair[0]].push_back(pair[1]);
            neighbourings[pair[1]].push_back(pair[0]);
        }
        
        for(int i = 0; i < n; i++){
            visited[i] = 0;
        }
        visited[source] = 1;
        stack<int> sta;
        sta.push(source);
       
        int current;
        while (!sta.empty()){
            current = sta.top();
            sta.pop();
            if (current == destination){
                return true;
            }
            for(auto neighbour: neighbourings[current]){
                if(visited[neighbour] == 0){
                    sta.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
        return false;
    }
};