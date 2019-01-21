/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (34.28%)
 * Total Accepted:    177.1K
 * Total Submissions: 515.4K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
/*        for(int i = 0;i < nums.size(); i++) { 
            for(int j = i + 1; j <= i + k && j < nums.size() ;j++)
                if (nums[i] == nums[j]) return true;
        }
        return false;
        */
/*        for(int i = 0;i < k && i < nums.size(); i++) {
            for(int j = i+1;j <= k && j < nums.size(); j++)
                if (nums[i] == nums[j]) return true;
        }

        for(int i = k+1;i < nums.size();i++) {
            for(int j = i-k;j < i;j++)
                if (nums[i] == nums[j]) return true;
        }

        return false;
        */
        k++;
        if (k > nums.size()) {
            unordered_set s(nums.begin(), nums.end());
            return s.size() != nums.size();
        }
        unordered_set<int> s(nums.begin(), nums.begin() + k);
        if (s.size() != k) return true;

        for(int i = k;i < nums.size(); i++) {
            s.erase(nums[i-k]);
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
