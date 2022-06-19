#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // answer is just total number of permutations of for m times go down and n times go right
        // we can arrange Going Down and Going Right on (m + n)! ways but we shouldn't differentiate going down and going right so
        // answer is (m+n)! / (m!*n!)

        long answer = 1;
        for(int i = m+1; i <= m+n; i++){
            answer *= i;
            answer /= i-m;
        }
        return (int)answer;
    }
};