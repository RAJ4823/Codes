// Link: https://leetcode.com/problems/reverse-string-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-string-ii
 *  RUNTIME: 7 ms
 *  MEMORY: 7.6 MB
 *  DATE: 11-13-2023, 9:24:58 AM
 *
 */

// Solution:

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += 2*k) {
            if(i+k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
