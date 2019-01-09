/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (49.80%)
 * Total Accepted:    108.4K
 * Total Submissions: 217.8K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k < 0 || k > n || 9*k < n) return res;
        vector<int> t;
        combinationSum(t,1, k, n);
        return res;
    }
    void combinationSum(vector<int> &t, int beg, int k, int n) {
        if (k == 0 && n == 0) {
            res.push_back(t); return ;
        }
        for (int i = beg; i < 10; i++) {
            if ((i)*k > n) return ;
            if (9*k < n) continue;
            t.push_back(i);
            combinationSum(t, i+1, k-1, n-i);
            t.pop_back();
        }
    }
};
