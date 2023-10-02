// Link: https://leetcode.com/problems/monotonic-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: monotonic-array
 *  RUNTIME: 108 ms
 *  MEMORY: 96.8 MB
 *  DATE: 9-29-2023, 9:52:39 AM
 *
 */

// Solution:

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int flag = -1;
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1])
                continue;
            if(flag == -1) 
                flag = (nums[i] < nums[i+1]);
            else if(flag != (nums[i] < nums[i+1])) 
                return false;
        }
        return true;
    }
};
