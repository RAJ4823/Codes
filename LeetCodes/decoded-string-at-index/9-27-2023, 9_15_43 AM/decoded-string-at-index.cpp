// Link: https://leetcode.com/problems/decoded-string-at-index

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: decoded-string-at-index
 *  RUNTIME: 2 ms
 *  MEMORY: 6.7 MB
 *  DATE: 9-27-2023, 9:15:43 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        ll len = 0, n = s.size();
        for(auto &ch: s) {
            if(isdigit(ch)) {
                len *= (ch - '0');
            } else {
                len += 1;
            }
        }

        for(ll i = n-1; i>=0; i--) {
            if(isdigit(s[i])) {
                len /= (s[i] - '0');
                k = k % len;
            } else {
                if(k == 0 || len == k) {
                    return string("") + s[i];
                }
                len--;
            }
        }
        return "";
    }
};
