/*
 * @lc app=leetcode id=539 lang=cpp
 *
 * [539] Minimum Time Difference
 *
 * https://leetcode.com/problems/minimum-time-difference/description/
 *
 * algorithms
 * Medium (46.88%)
 * Total Accepted:    24K
 * Total Submissions: 51.2K
 * Testcase Example:  '["23:59","00:00"]'
 *
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the
 * minimum minutes difference between any two time points in the list. 
 * 
 * Example 1:
 * 
 * Input: ["23:59","00:00"]
 * Output: 1
 * 
 * 
 * 
 * Note:
 * 
 * The number of time points in the given list is at least 2 and won't exceed
 * 20000.
 * The input time is legal and ranges from 00:00 to 23:59.
 * 
 * 
 */
class Solution {
public:
    int timePoint2int(string &timePoint) {
        /* stringstream ss(timePoint);
        int h, m;
        char c;
        ss >> h >> c >> m;
        return 60*h + m;*/
        timePoint[2]='\0';
        int h = atoi(timePoint.c_str());
        int m = atoi(timePoint.c_str()+3);
        return 60*h + m;
    }

    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() <= 1) return 0;
        vector<int> times(timePoints.size(), 0);
        int i = 0;
        for(auto &timePoint:timePoints) times[i++] = timePoint2int(timePoint);
        sort(times.begin(), times.end());

        const int m = 60*24;
        int res = times[0] + m - times[times.size()-1];
        for(int i = 1; i < times.size(); i++) {
            int t = times[i] - times[i-1];
            res = min(res, t);
        }

        return res;
    }
};
