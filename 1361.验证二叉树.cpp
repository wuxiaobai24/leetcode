/*
 * @lc app=leetcode.cn id=1361 lang=cpp
 *
 * [1361] 验证二叉树
 */

// @lc code=start
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> nodeCount(n, 0);
        for(int i = 0;i < n;i++) {
            if (!check(nodeCount, leftChild, rightChild, i)) return false;
            if (nodeCount[i] == n) return true;
        }
        return false;
    }

    bool check(vector<int> &nodeCount, vector<int> &leftChild, vector<int> &rightChild, int index) {
        if (index == -1) return true;
        if (nodeCount[index] == -1) {
            return false;
        } else if (nodeCount[index] != 0) return true;
        nodeCount[index] = -1;
        if (check(nodeCount, leftChild, rightChild, leftChild[index]) &&
            check(nodeCount, leftChild, rightChild, rightChild[index])) {
                int left = leftChild[index] == -1 ? 0: nodeCount[leftChild[index]];
                int right = rightChild[index] == -1 ? 0 : nodeCount[rightChild[index]];
                nodeCount[index] = 1 + left + right;
                return true;
        }
        return false;
    }
};
// @lc code=end

