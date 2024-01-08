// Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-product-difference-between-two-pairs
 *  RUNTIME: 19 ms
 *  MEMORY: 20.7 MB
 *  DATE: 12-18-2023, 12:45:45 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX, max1 = 0, max2 = 0;
        for(auto &val: nums) {
            if(val >= max1) {
                max2 = max1;
                max1 = val;
            } else if(val > max2) {
                max2 = val;
            }

            if(val <= min1) {
                min2 = min1;
                min1 = val;
            } else if(val < min2){
                min2 = val;
            }
        }
        return (max1 * max2) - (min1 * min2);
    }
};
