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
        while (head)
        {
            val.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        int temp;
        for(int i = val.size() - 1;i>=0;i--) {
            while (!st.empty() && val[i] >= st.top())
            {
                st.pop();
            }
            temp = st.empty() ? 0 : st.top();
            st.push(val[i]);
            val[i] = temp;
        }
        return val;
    }
};
// @lc code=end

