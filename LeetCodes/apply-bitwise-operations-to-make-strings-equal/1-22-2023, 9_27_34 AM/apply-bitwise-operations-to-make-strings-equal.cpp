// Link: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: apply-bitwise-operations-to-make-strings-equal
 *  RUNTIME: 26 ms
 *  MEMORY: 13.2 MB
 *  DATE: 1-22-2023, 9:27:34 AM
 *
 */

// Solution:

class Solution {
public:
    
    bool makeStringsEqual(string s, string target) {
        int n = s.length();
        if(s == target) return true;
        int sz = 0, tz = 0;
        for(auto &ch: s) if(ch == '0') sz++;
        for(auto &ch: target) if(ch == '0') tz++;
        if(sz == n || tz == n) return false;
        return true;
    }
};
