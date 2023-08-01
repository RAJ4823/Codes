// Link: https://leetcode.com/problems/first-missing-positive

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-missing-positive
 *  RUNTIME: 71 ms
 *  MEMORY: 41.1 MB
 *  DATE: 7-4-2023, 5:48:07 PM
 *
 */

// Solution:

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i=0; i<n; i++) {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};
