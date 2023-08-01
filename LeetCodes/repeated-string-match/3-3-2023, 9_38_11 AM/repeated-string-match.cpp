// Link: https://leetcode.com/problems/repeated-string-match

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: repeated-string-match
 *  RUNTIME: 12 ms
 *  MEMORY: 7.2 MB
 *  DATE: 3-3-2023, 9:38:11 AM
 *
 */

// Solution:

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string s = "";
        while(++count && s.size() < b.size()) s+= a;
        if(s.find(b) != string::npos) return count - 1;
        if((s+s).find(b) != string::npos) return count;
        return -1;
    }
};
