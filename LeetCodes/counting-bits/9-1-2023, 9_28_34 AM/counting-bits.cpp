// Link: https://leetcode.com/problems/counting-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: counting-bits
 *  RUNTIME: 3 ms
 *  MEMORY: 7.8 MB
 *  DATE: 9-1-2023, 9:28:34 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
