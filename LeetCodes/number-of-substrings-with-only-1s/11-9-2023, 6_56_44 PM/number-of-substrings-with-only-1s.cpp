// Link: https://leetcode.com/problems/number-of-substrings-with-only-1s

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-substrings-with-only-1s
 *  RUNTIME: 9 ms
 *  MEMORY: 9.4 MB
 *  DATE: 11-9-2023, 6:56:44 PM
 *
 */

// Solution:

class Solution {
public:
    int numSub(string s) {
        long long count = 0, ans = 0;
        long long mod = 1e9 + 7;

        for(auto &ch: s) {
            if(ch == '1') {
                count++;
            } else {
                long long sum = (count * (count + 1)) / 2;
                ans = (ans % mod + sum % mod);
                count = 0;
            }
        }

        long long sum = (count * (count + 1)) / 2;
        ans = (ans % mod + sum % mod);
        return ans;
    }
};
