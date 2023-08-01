// Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-arithmetic-subsequence-of-given-difference
 *  RUNTIME: 158 ms
 *  MEMORY: 54.9 MB
 *  DATE: 7-14-2023, 7:41:51 PM
 *
 */

// Solution:

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> dp; 
        
        int ans = 1; 
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - diff) != dp.end()) {
                dp[num] = dp[num - diff] + 1;
            } else {
                dp[num] = 1;
            }
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};
