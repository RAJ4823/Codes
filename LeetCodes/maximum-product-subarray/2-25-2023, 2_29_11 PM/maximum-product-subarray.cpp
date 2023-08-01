// Link: https://leetcode.com/problems/maximum-product-subarray

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-product-subarray
 *  RUNTIME: 11 ms
 *  MEMORY: 13.8 MB
 *  DATE: 2-25-2023, 2:29:11 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxi = 1, mini = 1;
        int ans = INT_MIN;

        for(auto &val: nums) {
            if(val < 0) swap(maxi, mini);
            
            maxi = max(maxi*val, val);
            mini = min(mini*val, val);
            ans = max(maxi, ans);
        }
        return ans;
    }
};
