// Link: https://leetcode.com/problems/left-and-right-sum-differences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: left-and-right-sum-differences
 *  RUNTIME: 3 ms
 *  MEMORY: 11.2 MB
 *  DATE: 2-26-2023, 8:07:05 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n, 0), rs(n, 0), ans(n);
        
        if(n == 1) {
            return {0};
        }
        
        for(int i=1; i<n; i++) {
            ls[i] = ls[i-1] + nums[i-1];
        }
        for(int i=n-2; i>=0; i--) {
            rs[i] = rs[i+1] + nums[i+1];
        }
        for(int i=0; i<n; i++) {
            ans[i] = abs(ls[i] - rs[i]);
        }
        return ans;
    }
};
