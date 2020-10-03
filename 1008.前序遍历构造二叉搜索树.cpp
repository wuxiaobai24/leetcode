/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, preorder.size() - 1);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder, int first, int last) {
        if (first > last) return nullptr;
        TreeNode *tree = new TreeNode(preorder[first]);
        int rightFirst = first + 1;
        while(rightFirst <= last && preorder[rightFirst] < preorder[first])
            rightFirst++;
        tree->left = bstFromPreorder(preorder, first + 1, rightFirst - 1);
        tree->right = bstFromPreorder(preorder, rightFirst, last);
        return tree;
    }
};
// @lc code=end

