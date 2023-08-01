// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-common-divisor-of-strings
 *  RUNTIME: 0 ms
 *  MEMORY: 6.9 MB
 *  DATE: 2-1-2023, 10:42:47 AM
 *
 */

// Solution:

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = __gcd(n, m);
        string ans = str1.substr(0, len);
        for(int i = 0; i<n;i+=len) {
            if(str1.substr(i,len) != ans) return "";
        }
        for(int i = 0; i<m;i+=len) {
            if(str2.substr(i,len) != ans) return "";
        }
        return ans;
    }
};
