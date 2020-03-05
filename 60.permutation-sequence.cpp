/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (32.29%)
 * Total Accepted:    129.6K
 * Total Submissions: 401K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "123456789";
        string res;

        vector<int> d(n); d[0] = 1;
        for(int i = 1; i < n; i++) d[i] = d[i-1] * i;
        
        // make sure k start from zero.
        k--;

        for(int i = n-1; i >= 0; i--) {
            int index = k/d[i];
            k = k % d[i];
            // cout << k << " " << s[index] << endl;
            res.push_back(s[index]);
            s.erase(s.begin() + index);
        }
        

        return res;
    }
};

