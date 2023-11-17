// Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-equal-sum-of-two-arrays-after-replacing-zeros
 *  RUNTIME: 148 ms
 *  MEMORY: 130.6 MB
 *  DATE: 10-31-2023, 7:29:07 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, sum2 = 0;
        bool hasZero1 = false, hasZero2 = false;
        for(ll val: nums1) {
            if(val == 0) {
                hasZero1 = true;
                sum1 += 1;
            } else {
                sum1 += val;
            }
        }
        for(ll val: nums2) {
            if(val == 0) {
                hasZero2 = true;
                sum2 += 1;
            } else {
                sum2 += val;
            }
        }
        
        if(!hasZero1 && !hasZero2) 
            return (sum1 == sum2) ? sum1 : -1;
        if(!hasZero1) {
            if(sum1 < sum2) return -1;
        }
        if(!hasZero2) {
            if(sum2 < sum1) return -1;
        }   
        return max(sum1, sum2);
    }
};
