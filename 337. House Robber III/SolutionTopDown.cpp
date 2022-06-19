#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime: 51 ms, faster than 8.15% of C++ online submissions for House Robber III.
// Memory Usage: 36.8 MB, less than 7.75% of C++ online submissions for House Robber III.
class Solution {
public:
    typedef unordered_map<bool, int> bool_to_int;
    typedef unordered_map<TreeNode*, bool_to_int> my_map;
    my_map memo; 
    int robHelper(TreeNode* root, bool parent_robbed){
        if (memo.find(root) != memo.end()){
            if (memo[root].find(parent_robbed) != memo[root].end()){
                return memo[root][parent_robbed];
            }
        }
        int not_rob = robHelper(root->left, false) + robHelper(root->right, false);
        if (parent_robbed){
            memo[root][parent_robbed] = not_rob;
        }
        else{
            int rob = root->val + robHelper(root->left, true) + robHelper(root->right, true);
            memo[root][parent_robbed] = max(rob, not_rob);
        }
        return memo[root][parent_robbed];
    }
    int rob(TreeNode* root) {
        memo[nullptr][false] = 0;
        memo[nullptr][true] = 0;
        return robHelper(root, false);
    }
};