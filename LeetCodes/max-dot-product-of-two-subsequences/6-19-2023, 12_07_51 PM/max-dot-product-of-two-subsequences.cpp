// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-dot-product-of-two-subsequences
 *  RUNTIME: 57 ms
 *  MEMORY: 13.1 MB
 *  DATE: 6-19-2023, 12:07:51 PM
 *
 */

// Solution:

class Solution {
private:
    vector<vector<int>> dp;
    int n1, n2;
    int find(int i, int j,vector<int> &nums1,vector<int> &nums2) {
        if(i >= n1 || j >= n2) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];

        int take = INT_MIN, nottake = INT_MIN;
        take = nums1[i] * nums2[j] + find(i+1, j+1, nums1, nums2);
        nottake = max(find(i+1, j, nums1, nums2), find(i, j+1, nums1, nums2));
        return dp[i][j] = max(take, nottake);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        dp.resize(n1, vector<int> (n2, INT_MIN));

        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        for(auto &val: nums1) min1 = min(min1, val), max1 = max(max1, val);
        for(auto &val: nums2) min2 = min(min2, val), max2 = max(max2, val);

        int ans = find(0, 0, nums1, nums2); 
        if(ans == 0) {
            return max({min1*min2, max1*max2, min1*max2, min2*max1});
        }
        return ans;
    }
};
