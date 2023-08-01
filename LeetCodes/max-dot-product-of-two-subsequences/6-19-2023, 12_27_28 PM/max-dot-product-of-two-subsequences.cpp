// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-dot-product-of-two-subsequences
 *  RUNTIME: 36 ms
 *  MEMORY: 9.4 MB
 *  DATE: 6-19-2023, 12:27:28 PM
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

        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        int max1 = *max_element(nums1.begin(), nums1.end());
        int max2 = *max_element(nums2.begin(), nums2.end());
        int base = max({min1*min2, max1*max2, min1*max2, min2*max1});
        
        for(int i=n1-1; i>=0; i--) {
            for(int j=n2-1; j>=0; j--) {
                dp[j] = max({nums1[i] * nums2[j] + prev[j+1], prev[j], dp[j+1]});
            }
            prev = dp;
        }
        int ans = dp[0];

        if(ans == 0) return base;
        return ans;
    }
};
