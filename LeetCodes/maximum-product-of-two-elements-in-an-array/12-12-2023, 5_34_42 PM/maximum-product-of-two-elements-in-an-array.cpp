// Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-product-of-two-elements-in-an-array
 *  RUNTIME: 7 ms
 *  MEMORY: 10.3 MB
 *  DATE: 12-12-2023, 5:34:42 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(auto &val: nums) {
            if(val >= max1) {
                max2 = max1;
                max1 = val;
            } else if (val >= max2) {
                max2 = val;
            }
        }
        return (max1 - 1)*(max2 - 1);
    }
};
