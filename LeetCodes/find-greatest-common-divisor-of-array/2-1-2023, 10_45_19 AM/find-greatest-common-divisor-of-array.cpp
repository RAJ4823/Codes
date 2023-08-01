// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-greatest-common-divisor-of-array
 *  RUNTIME: 4 ms
 *  MEMORY: 12.4 MB
 *  DATE: 2-1-2023, 10:45:19 AM
 *
 */

// Solution:

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto &val: nums) {
            if(val < mini) mini = val;
            if(val > maxi) maxi = val;
        }
        return __gcd(maxi, mini);
    }
};
