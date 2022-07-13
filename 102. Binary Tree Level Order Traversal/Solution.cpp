#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levels;

    void helper(TreeNode* root, int height){
        if (root == nullptr){
            return;
        }
        if (height < levels.size() - 1){
            vector<int> temp;
            levels.push_back(temp);
        }
        levels[height].push_back(root->val);
        helper(root->left, height+1);
        helper(root->right, height+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return levels;
    }
};