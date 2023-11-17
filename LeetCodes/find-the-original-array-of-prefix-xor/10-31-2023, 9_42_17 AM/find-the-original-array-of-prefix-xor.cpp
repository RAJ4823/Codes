// Link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-original-array-of-prefix-xor
 *  RUNTIME: 88 ms
 *  MEMORY: 76.4 MB
 *  DATE: 10-31-2023, 9:42:17 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        for(int i=1; i<n; i++) {
            ans[i] = pref[i-1] ^ pref[i];
        }
        return ans;
    }
};
