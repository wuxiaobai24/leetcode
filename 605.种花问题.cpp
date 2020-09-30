/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        bool prev = true, cur = flowerbed[0] == 0, next;
        for(int i = 1;i < flowerbed.size() && n != 0;i++) {
            next = flowerbed[i] == 0;
            if (prev && cur && next) { n--; cur = false; }
            prev = cur;
            cur = next;
        }
        if (prev && cur) n--;
        return n <= 0;
    }
};
// @lc code=end

