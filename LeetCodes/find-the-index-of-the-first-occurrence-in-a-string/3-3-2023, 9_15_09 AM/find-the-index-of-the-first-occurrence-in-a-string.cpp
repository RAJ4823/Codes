// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-index-of-the-first-occurrence-in-a-string
 *  RUNTIME: 4 ms
 *  MEMORY: 6.4 MB
 *  DATE: 3-3-2023, 9:15:09 AM
 *
 */

// Solution:

class Solution {
public:
    int strStr(string str, string s) {
        int n = str.size(), m = s.size();
        if(m > n) return -1;
        for(int i=0; i<n; i++) {
            if(str[i] == s[0]) {
                string substr = str.substr(i, m);
                if(substr == s) return i;
            }
        }
        return -1;
    }
};
