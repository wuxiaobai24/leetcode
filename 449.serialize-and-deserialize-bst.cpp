/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (44.95%)
 * Total Accepted:    44.8K
 * Total Submissions: 99.7K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You just need to ensure that a binary search tree can be serialized to
 * a string and this string can be deserialized to the original tree
 * structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void int2chars(int val, string &str) {
        //cout << val << "\t";
        for(int i = 0;i < sizeof(int);i++) {
            str.push_back((char)(val&0xf));
            val = val >> 4;
        }
        //cout << chars2int(str, str.size() - sizeof(int)) << endl;
    }

    int chars2int(string &str, int index) {
        int res = 0;
        for(int i = index + sizeof(int) - 1; i >= index;i--){
            res = res << 4;
            //cout << (int)(str[i]) << " ";
            res += (int)(str[i]);
        }
        return res;
    }

    void serialize(TreeNode *root, string &str) {
        if (root) {
            int2chars(root->val, str);
            serialize(root->left, str);
            serialize(root->right, str);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        //cout << res.size()/sizeof(int) << endl;
        return res;
    }

    TreeNode *insertBST(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->val > val) root->left = insertBST(root->left, val);
        else if (root->val < val) root->right = insertBST(root->right, val);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        int c = 0;
        for(int i = 0;i < data.size(); i += sizeof(int)) {
           int val = chars2int(data, i);
           //cout << val << " ";
           root = insertBST(root, val);
           c++;
        }
        //cout << c << endl;
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
