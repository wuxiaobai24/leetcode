/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (36.56%)
 * Total Accepted:    215.6K
 * Total Submissions: 589.8K
 * Testcase Example:  '{}'
 *
 * Given a binary tree
 * 
 * 
 * struct TreeLinkNode {
 * ⁠ TreeLinkNode *left;
 * ⁠ TreeLinkNode *right;
 * ⁠ TreeLinkNode *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the
 * same level, and every parent has two children).
 * 
 * 
 * Example:
 * 
 * Given the following perfect binary tree,
 * 
 * 
 * ⁠    1
 * ⁠  /  \
 * ⁠ 2    3
 * ⁠/ \  / \
 * 4  5  6  7
 * 
 * 
 * After calling your function, the tree should look like:
 * 
 * 
 * ⁠    1 -> NULL
 * ⁠  /  \
 * ⁠ 2 -> 3 -> NULL
 * ⁠/ \  / \
 * 4->5->6->7 -> NULL
 * 
 * 
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL) return ;
     //   TreeLinkNode *left, *right;
     //   connect(root, left, right);
        
        // connect left tree and right tree
        TreeLinkNode *left = root->left;
        TreeLinkNode *right = root->right;
        while(left&&right) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connect(root->left);
        connect(root->right);
    }

    /* void connect(TreeLinkNode *root, TreeLinkNode *&left, TreeLinkNode *&right) {
        if (root->left == NULL && root->right == NULL) {
            left = right = root; return ;
        }
        TreeLinkNode *left_left, *left_right, *right_left, *right_right;
        connect(root->left, left_left, left_right);
        connect(root->right, right_left, right_right);
        root->left->next = root->right;
        left_right->next = right_left;
        left = left_left;
        right = right_right;
        
    } */
};
