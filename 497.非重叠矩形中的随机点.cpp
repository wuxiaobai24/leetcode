/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

// @lc code=start
class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        sum = 0;
        for(auto v: rects) {
            int size = (v[2] - v[0] + 1) * (v[3] - v[1] + 1);
            sum += size;
            _size.push_back(size);
            _rects.push_back(v);
        }
        // cout << sum << endl;
        // _rects = rects;
    }
    
    vector<int> pick() {
        int r = rand() % sum, i;
        // cout << r << endl;
        for(i = 0;i < _size.size() && r >= _size[i]; i++) {
            r -= _size[i];
        }
        // cout << r << " " << i << endl;
        return pick(i);
    }

    vector<int> pick(int i) {
        vector<int> res(2);
        int x1 = _rects[i][0], y1 = _rects[i][1], x2 = _rects[i][2], y2 = _rects[i][3];
        res[0] = x1 + rand() % (x2 - x1 + 1);
        res[1] = y1 + rand() % (y2 - y1 + 1);
        return res;
    }

    vector<vector<int>> _rects;
    vector<int> _size;
    int sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

