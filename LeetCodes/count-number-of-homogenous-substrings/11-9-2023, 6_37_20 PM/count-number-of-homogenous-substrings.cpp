// Link: https://leetcode.com/problems/count-number-of-homogenous-substrings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-number-of-homogenous-substrings
 *  RUNTIME: 24 ms
 *  MEMORY: 12 MB
 *  DATE: 11-9-2023, 6:37:20 PM
 *
 */

// Solution:

class Solution {
public:
    int countHomogenous(string s) {
        long long curr = '0', count = 0, ans = 0;
        long long MOD = 1e9+7;

        for(auto &ch: s) {
            if(ch == curr) {
                count++;
            } else {
                long long sum = (count * (count + 1)) / 2;
                ans = (ans % MOD + sum % MOD) % MOD;
                curr = ch;
                count = 1;
            }
        }
        long long sum = (count * (count + 1)) / 2;
        ans = (ans % MOD + sum % MOD) % MOD;
        return ans;
    }
};
