// Link: https://leetcode.com/problems/subarray-product-less-than-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: subarray-product-less-than-k
 *  RUNTIME: 97 ms
 *  MEMORY: 61.4 MB
 *  DATE: 2-25-2023, 2:48:57 PM
 *
 */

// Solution:

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prod = 1, count = 0;
        int i = 0, j = 0, n = nums.size();
        if(k == 0) return 0;

        while(j < n) {
            prod *= nums[j];
            while(i <= j && prod >= k) {
                prod /= nums[i++];
            }
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};
