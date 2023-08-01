// Link: https://leetcode.com/problems/rotate-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: rotate-string
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 1-14-2023, 9:51:18 AM
 *
 */

// Solution:

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length()!=B.length()) return false;
        if((A+A).find(B)!=string::npos) return true;
        return false;
    }
};
