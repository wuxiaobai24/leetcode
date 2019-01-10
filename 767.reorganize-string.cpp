/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (40.48%)
 * Total Accepted:    18.2K
 * Total Submissions: 45K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 *
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 *
 * Example 1:
 *
 *
 * Input: S = "aab"
 * Output: "aba"
 *
 *
 * Example 2:
 *
 *
 * Input: S = "aaab"
 * Output: ""
 *
 *
 * Note:
 *
 *
 * S will consist of lowercase letters and have length in range [1, 500].
 *
 *
 *
 *
 */
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> cmap;
        for(auto c:S) cmap[c]++;
        auto cmp = [](auto &p1, auto &p2) { return p1.second < p2.second; };
        priority_queue<pair<char, int>, vector<pair<char, int>> ,decltype(cmp)> q(cmp);
        for(auto p:cmap) q.push(p);
        string res;
        while(!q.empty()) {
            auto p1 = q.top(); q.pop();
            if (p1.second == 0) continue;
            res.push_back(p1.first);
            p1.second--;
            pair<char, int> p2;
            p2.second = 0;
            for(int i = 0;i < p1.second; i++) {
                if (p2.second == 0) {
                    if (q.empty()) { cout << res << endl; return string(""); }
                    p2 = q.top(); q.pop();
                }
                res.push_back(p2.first); p2.second--;
                res.push_back(p1.first);
            }
            if (p2.second != 0) q.push(p2);
        }
        return res;
    }
};
