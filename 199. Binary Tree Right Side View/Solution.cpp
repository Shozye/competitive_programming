#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> heights;
        vector<int> vision;
        if (root == nullptr){
            return vision;
        }
        int vision_height = -1;
        stack.push_back(root);
        heights.push_back(0);
        while (!stack.empty()){
            TreeNode* elem = stack.back();
            int height = heights.back();
            stack.pop_back();
            heights.pop_back();

            if (height > vision_height){
                vision.push_back(elem->val);
                vision_height++;
            }
            if (elem->left != nullptr){
                stack.push_back(elem->left);
                heights.push_back(height+1);
            }
            if (elem->right != nullptr){
                stack.push_back(elem->right);
                heights.push_back(height+1);
            }
        }
        return vision;
    }
};