/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    // TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    //     if (pre.size() == 0) return nullptr;
    //     TreeNode *root = new TreeNode(pre[0]);
    //     if (pre.size() == 1) return root;
    //     int leftNode = pre[1];
    //     int leftLen = 0;
    //     while (leftLen < post.size() && post[leftLen] != leftNode)
    //     {
    //         leftLen++;
    //     }
    //     leftLen += 1;
    //     vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + leftLen);
    //     vector<int> rightPre(pre.begin() + 1 + leftLen, pre.end());
    //     vector<int> leftPost(post.begin(), post.begin() + leftLen);
    //     vector<int> rightPost(post.begin() + leftLen, post.end() - 1);

    //     root->left = constructFromPrePost(leftPre, leftPost);
    //     root->right = constructFromPrePost(rightPre, rightPost);
    //     return root;
    // }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost(pre, post, 0, pre.size() -1, 0 ,post.size() - 1);
    }
    TreeNode* constructFromPrePost(vector<int> &pre, vector<int> &post, 
        int preFirst, int preLast, int postFirst, int postLast) {
        if (preFirst > preLast || postFirst > postLast) return nullptr;
        TreeNode *root = new TreeNode(pre[preFirst]);
        preFirst++; postLast--;
        if (preFirst > preLast || postFirst > postLast) return root;
        int leftPostLast = postFirst;
        while (leftPostLast <= postLast && post[leftPostLast] != pre[preFirst])
        {
            leftPostLast++;
        }
        int leftPreLast = leftPostLast - postFirst + preFirst;
        root->left = constructFromPrePost(pre, post, preFirst, leftPreLast, postFirst, leftPostLast);
        root->right = constructFromPrePost(pre, post, leftPreLast + 1, preLast, leftPostLast + 1, postLast);
        return root;
    }
};
// @lc code=end

