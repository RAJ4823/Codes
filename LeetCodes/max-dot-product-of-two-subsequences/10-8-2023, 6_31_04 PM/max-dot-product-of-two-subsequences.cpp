// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-dot-product-of-two-subsequences
 *  RUNTIME: 38 ms
 *  MEMORY: 13.5 MB
 *  DATE: 10-8-2023, 6:31:04 PM
 *
 */

// Solution:

class Solution {
public:
    int n, m;
    int find(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp) {
        if(i == n || j == m)
            return INT_MIN;
        if(dp[i][j] != INT_MIN) 
            return dp[i][j];

        int take = nums1[i] * nums2[j] + max(find(i+1, j+1, nums1, nums2, dp), 0);
        int nottake = max(find(i+1, j, nums1, nums2, dp), find(i, j+1, nums1, nums2, dp));
        return dp[i][j] = max(take, nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return find(0, 0, nums1, nums2, dp);
    }
};
