/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.17%)
 * Total Accepted:    222.5K
 * Total Submissions: 567.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int len = nums.size();
        vector<vector<int>> res;
        if (len == 0) return res;

        sort(nums.begin(), nums.end());
        premuteUnique(nums, res, 0);
        return res;
    }

    void premuteUnique(vector<int> &nums, vector<vector<int>> &res, int index) {
        if (index >= nums.size())  {
            res.push_back(nums);
            return;
        }
        int len = nums.size();
        
        int last_index = -1;
        for(int i = index; i < len; i++) {
            if (last_index != -1 && nums[last_index] == nums[i]) continue;
            swap(nums[index], nums[i]);
            premuteUnique(nums, res, index + 1);
            swap(nums[index], nums[i]);
            last_index = i;
        }
    }
};

