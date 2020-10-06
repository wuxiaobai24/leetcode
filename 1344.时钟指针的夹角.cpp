/*
 * @lc app=leetcode.cn id=1344 lang=cpp
 *
 * [1344] 时钟指针的夹角
 */

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        minutes = minutes % 60;
        hour = hour * 60 + minutes;
        minutes = minutes * 12;
        return min(720 - abs(hour - minutes), abs(hour - minutes)) / 2.0;
    }

};
// @lc code=end

