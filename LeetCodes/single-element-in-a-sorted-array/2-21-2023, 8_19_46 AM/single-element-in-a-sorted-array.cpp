// Link: https://leetcode.com/problems/single-element-in-a-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: single-element-in-a-sorted-array
 *  RUNTIME: 33 ms
 *  MEMORY: 22.4 MB
 *  DATE: 2-21-2023, 8:19:46 AM
 *
 */

// Solution:

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i<j) {
            if(nums[i] == nums[i+1]) i+=2;
            else return nums[i];
            if(nums[j] == nums[j-1]) j-=2;
            else return nums[j];
        }
        return nums[i];
    }
};
