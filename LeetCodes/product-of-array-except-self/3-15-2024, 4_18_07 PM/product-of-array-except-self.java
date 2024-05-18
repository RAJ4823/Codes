// Link: https://leetcode.com/problems/product-of-array-except-self

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: product-of-array-except-self
 *  RUNTIME: 2 ms
 *  MEMORY: 54.8 MB
 *  DATE: 3-15-2024, 4:18:07 PM
 *
 */

// Solution:

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];

        suffix[n-1] = nums[n-1];
        prefix[0] = nums[0];

        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }

        int[] ans = new int[n];
        ans[0] = suffix[1];
        ans[n-1] = prefix[n-2];
        for(int i=1; i<n-1; i++) {
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
}
