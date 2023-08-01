// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sign-of-the-product-of-an-array
 *  RUNTIME: 4 ms
 *  MEMORY: 10.2 MB
 *  DATE: 5-2-2023, 9:19:44 AM
 *
 */

// Solution:

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto &val: nums) {
            if(val == 0) return 0;
            if(val < 0) neg++;
        }
        return (neg%2)? -1: 1;
    }
};
