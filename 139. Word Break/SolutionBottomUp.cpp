#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        // using set for fast counting
        set<string> word_set;
        for(auto word: wordDict){
            word_set.insert(word);
        }

        bool dp[len + 1]; 
        for(int i = 1; i <= len; i++){
            dp[i] = false;
        }
        // dp[i] is the answer to problem with s[0:1]
        // dp[0] is base case for empty string
        dp[0] = true;
        // so s = "leetcode", dp[4] is answer to problem
        // 'if we can make "leet" '

        string string_to_check;
        // 'i' is end pointer
        // we starting from 1 because dp[0] is solved before
        for(int i = 1; i <= len; i++){
            // 'j' is start pointer
            for(int j = 0; j < i; j++){
                // if  s[0..j] is doable
                // and s[j+1..i] is in wordlist
                // then s[0..i] is doable
                string check_word = s.substr(j, i-j);
                bool is_in = word_set.count(check_word);
                if(dp[j] && is_in){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
