/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Node* connect(Node* root) {
    //     if (!root) return nullptr;
    //     Node* left = root->left;
    //     Node *right = root->right;
    //     while (left && right)
    //     {
    //         left->next = right;
    //         left = left->right;
    //         right = right->left;
    //     }
    //     connect(root->left);
    //     connect(root->right);
    //     return root;
    // }

    // Node* connect(Node* root) {
    //     if (root && root->left) {
    //         root->left->next = root->right;
    //         root->right->next = root->next ? root->next->left : nullptr;
    //         connect(root->left);
    //         connect(root->right);
    //     }
    //     return root;
    // }

    Node* connect(Node *root) {
        Node* nextLayer = root;
        Node* p;
        while(nextLayer) {
            p = nextLayer;
            nextLayer = p->left;
            while (p && nextLayer)
            {
                p->left->next = p->right;
                p->right->next = p->next ? p->next->left : nullptr;
                p = p->next;
            }
        }
        return root;
    }
};
// @lc code=end

