// Link: https://leetcode.com/problems/maximum-odd-binary-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-odd-binary-number
 *  RUNTIME: 8 ms
 *  MEMORY: 7 MB
 *  DATE: 9-26-2023, 5:07:44 PM
 *
 */

// Solution:

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int ones = 0, n = s.size();
        for(auto &ch: s) {
            ans += '0';
            ones += (ch - '0');
        }
        ans[n - 1] = '1';
        ones--;
        int i = 0;
        while(ones--) {
            ans[i++] = '1';
        }
        return ans;
    }
};
