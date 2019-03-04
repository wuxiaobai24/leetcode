/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (29.95%)
 * Total Accepted:    184.2K
 * Total Submissions: 615K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    void multipluOne(string &num1, int n2, string &res) {
        int a = 0;
        for(auto it  = num1.rbegin(); it != num1.rend(); it++) {
            a = (*it - '0') * n2 + a;
            res.push_back('0' + a%10);
            a /= 10; 
        }
        while(a != 0) {
            res.push_back('0' + a%10);
            a /= 10;
        }
    }
    void add(string &res, string &s) {
        int a = 0;
        auto it1 = res.begin(), it2 = s.begin();
        while(it1 != res.end() && it2 != s.end()) {
            a += (*it1 - '0') + (*it2 - '0');
            *it1 = a % 10 + '0';
            a /= 10;
            it1++; it2++;
        }
        while(it2 != s.end()) {
            a += (*it2 - '0');
            res.push_back(a% 10 + '0');
            a /= 10;
            it2++;
        }
        while(a != 0) {
            res.push_back(a % 10 + '0');
            a /= 10;
        }
    }
    string multiply(string num1, string num2) {
        int  index = 0;
        string r;
        string res = "0";
        for(auto it = num2.rbegin(); it != num2.rend(); it++) {
            string temp = r;
            multipluOne(num1, *it - '0', temp);
            add(res, temp);
            r.push_back('0');
        }
        int i = res.size() - 1;
        while(i > 0 && res[i] == '0') {
            res.pop_back();
            i--;
        }
        return string(res.rbegin(), res.rend());
    }
};

