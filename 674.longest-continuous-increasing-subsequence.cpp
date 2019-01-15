/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (43.50%)
 * Total Accepted:    54.5K
 * Total Submissions: 125.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the length of longest continuous
 * increasing subsequence (subarray).
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5], its
 * length is 3. 
 * Even though [1,3,5,7] is also an increasing subsequence, it's not a
 * continuous one where 5 and 7 are separated by 4. 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2], its
 * length is 1. 
 * 
 * 
 * 
 * Note:
 * Length of the array will not exceed 10,000.
 * 
 */
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i < nums.size();) {
            int j;
            for(j = i+1;j < nums.size();j++)
                if (nums[j-1] >= nums[j]) break;
            res = max(res, j-i);
            i = j;
        }
        return res;
    }
};
