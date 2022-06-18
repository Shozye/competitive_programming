#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordDict;
    unordered_map<string, bool> memo;
    bool dp(string s){
        int len = s.size();
        if (len == 0){
            return true;
        }
        if (memo.find(s) != memo.end()){
            return memo.at(s);
        }
        string string_to_check;
        for(int i = 0; i < len; i++){
            string_to_check += s.front();
            s.erase(0, 1);
            bool contains = false;
            for(auto word: wordDict){
                if (word == string_to_check){
                    contains = true;
                    break;
                }
            }
            if (contains){
                memo[s] = dp(s);
                if (memo[s]){
                    return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        this->wordDict = wordDict;
        return dp(s);
    }
};