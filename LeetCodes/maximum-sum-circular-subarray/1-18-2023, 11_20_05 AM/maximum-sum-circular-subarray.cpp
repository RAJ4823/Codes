// Link: https://leetcode.com/problems/maximum-sum-circular-subarray

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-sum-circular-subarray
 *  RUNTIME: 65 ms
 *  MEMORY: 39.8 MB
 *  DATE: 1-18-2023, 11:20:05 AM
 *
 */

// Solution:

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int total = 0, maxi = INT_MIN, currMaxi = 0;
       int mini = INT_MAX, currMini = 0;
        for (int x : nums) {
            currMaxi = max(x, currMaxi + x);  
            maxi = max(maxi, currMaxi); 
            
            currMini = min(x, currMini + x); 
            mini = min(mini, currMini); 
            total += x;
        }
        if(maxi > 0)
            return max(maxi, total - mini);
        return maxi;
    }
};
