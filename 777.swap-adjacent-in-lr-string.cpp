/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (32.19%)
 * Total Accepted:    10K
 * Total Submissions: 31K
 * Testcase Example:  '"X"\n"L"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 *
 * Example:
 *
 *
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: True
 * Explanation:
 * We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 *
 *
 * Note:
 *
 *
 * 1 <= len(start) = len(end) <= 10000.
 * Both start and end will only consist of characters in {'L', 'R', 'X'}.
 *
 *
 */
class Solution {
public:
    bool state_X(int &state, char s1, char s2) {
        if (s1 == s2) return true;
        else if (s1 == 'R' && s2 == 'X') { state = 1; return true; }
        else if (s1 == 'X' && s2 == 'L') { state = -1; return true; }
        else return false;

    }
    bool state_R(int &state, char s1, char s2) {
        if (s1 == s2) return true;
        else if (s1 == 'R' && s2 == 'X') { state++; return true; }
        else if (s1 == 'X' && s2 == 'R') {state--; return true;}
        else return false;
    }
    bool state_L(int &state, char s1, char s2) {
        if (s1 == s2) return true;
        else if (s1 == 'X' && s2 == 'L') { state--; return true; }
        else if (s1 == 'L' && s2 == 'X') { state++; return true; }
        else return false;
    }
    bool canTransform(string start, string end) {
        int state = 0;
        bool flag = true;
        for(int  i = 0;i < start.size(); i++) {
            if (state == 0 && state_X(state, start[i], end[i])) ;
            else if (state > 0 && state_R(state, start[i], end[i])) ;
            else if (state < 0 && state_L(state, start[i], end[i])) ;
            else return false;
//            cout << state << " ";
        }
        return state == 0;
    }
};
