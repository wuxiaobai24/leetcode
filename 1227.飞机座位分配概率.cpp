/*
 * @lc app=leetcode.cn id=1227 lang=cpp
 *
 * [1227] 飞机座位分配概率
 */

// @lc code=start
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // double sum = 1.0;
        // for(int k = 2;k <= n;k++) {
            // res = sum / k;
            // sum += res;
        // }
        // return res;
        return n > 1 ? 0.5 : 1.0;
    }
};
// @lc code=end

