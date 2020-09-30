/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == nullptr) return root;
        if (d == 1) {
            TreeNode *p = new TreeNode(v);
            p->left = root;
            return p;
        }
        if (d == 2) {
            TreeNode *left = new TreeNode(v);
            TreeNode *right = new TreeNode(v);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
            return root;
        }
        root->left = addOneRow(root->left, v, d - 1);
        root->right = addOneRow(root->right, v, d - 1);
        return root;
    }
};
// @lc code=end

