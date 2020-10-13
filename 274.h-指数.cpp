/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i, j;
        // 0 1 3 6 5
        // 5 4 3 2 1
        for(i = citations.size() - 1, j = 1;i >= 0 && citations[i] >= j;i--,j++) {
        }
        return j - 1;
    }
};
// @lc code=end

