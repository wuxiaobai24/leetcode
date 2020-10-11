/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> val;
        stack<pair<int, int>> st;
        int index = 0;
        while (head)
        {
            val.push_back(0);
            while (!st.empty() && st.top().first < head->val)
            {
                val[st.top().second] = head->val;
                st.pop();
            }
            st.push(make_pair(head->val, index++));
            head = head->next;
        }
        return val;
    }
};
// @lc code=end

