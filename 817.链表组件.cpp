/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        // unordered_set<int> iset(G.begin(), G.end());
        vector<bool> iset(10000, false);
        for(int v: G) iset[v] = true;

        int c = 0;
        bool flag = false;
        while (head)
        {
            if (iset[head->val]) {
                flag = true;
            } else {
                c += flag;
                flag = false;
            }
            head = head->next;
        }
        c += flag;
        return c;
    }
};
// @lc code=end

