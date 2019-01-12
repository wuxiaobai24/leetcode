/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (27.72%)
 * Total Accepted:    179.5K
 * Total Submissions: 646.4K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
/*        int end = nums.size()-1;
        for(int i = 0;i <= end;) {
            if (nums[i] < 1 || nums[i] > end + 1 ||
                    (nums[i] != i+1 && nums[i] == nums[nums[i]-1])) {
                //cout << i << nums[i] << endl;
                swap(nums[i], nums[end]);
                end--;
            } else if (nums[i] != i + 1) {
                int j = nums[i] - 1;
                swap(nums[i], nums[j]);
            } else i++;
        }
        return end+2;
*/
        for(int i = 0;i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0;i <nums.size(); i++)
            if (nums[i] != i+1) return i+1;
        return nums.size() + 1;
    }
};
