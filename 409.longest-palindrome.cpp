/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (47.08%)
 * Total Accepted:    85K
 * Total Submissions: 180.3K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cmap;
        for(auto c: s) cmap[c]++;
        int res = 0;
        int flag = 0;
        for(auto &p: cmap) {
            if (p.second % 2) { res += p.second - 1; flag = 1; }
            else res += p.second;
        }

        return res + flag;
    }
};
