// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-dot-product-of-two-subsequences
 *  RUNTIME: 23 ms
 *  MEMORY: 9.5 MB
 *  DATE: 6-19-2023, 12:29:56 PM
 *
 */

// Solution:

class Solution {
private:
    vector<int> dp;
    vector<int> prev;
    int n1, n2;
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        dp.resize(n2+1, 0);
        prev.resize(n2+1, 0);

        int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
        for(auto &val: nums1) min1 = min(min1, val), max1 = max(max1, val);
        for(auto &val: nums2) min2 = min(min2, val), max2 = max(max2, val);
        int base = max({min1*min2, max1*max2, min1*max2, min2*max1});
        
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                dp[j] = max(nums1[i] * nums2[j] + prev[j+1], max(prev[j], dp[j+1]));
            }
            prev = dp;
        }
        int ans = dp[0];

        if(ans == 0) return base;
        return ans;
    }
};
