/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

// @lc code=start
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        _radius = radius;
        _x = x_center;
        _y = y_center;
        // srand(time(0));
    }
    
    vector<double> randPoint() {
    //    vector<double> res(2);
    //    double r = sqrt(_radius * _radius * (rand() / (double)RAND_MAX));
    //    double rad = 2 * M_PI * ((rand() % RAND_MAX) / (double)RAND_MAX);
    //    res[0] = cos(rad) * r + _x;
    //    res[1] = sin(rad) * r + _y;
    //    return res;
        vector<double> res(2);
        double x, y;
        do {
            x =  -1 +( 2 * ((double)rand() / RAND_MAX));
            y = -1 + ( 2 * ((double)rand() / RAND_MAX));
        } while(x*x + y*y > 1);
        res[0] = x*_radius + _x;
        res[1] = y*_radius + _y;
        return res;
    }

private:
    double _radius, _x, _y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

