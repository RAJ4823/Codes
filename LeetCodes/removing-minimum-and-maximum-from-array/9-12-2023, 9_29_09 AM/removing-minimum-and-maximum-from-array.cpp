// Link: https://leetcode.com/problems/removing-minimum-and-maximum-from-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: removing-minimum-and-maximum-from-array
 *  RUNTIME: 139 ms
 *  MEMORY: 88.4 MB
 *  DATE: 9-12-2023, 9:29:09 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_index = 0, max_index = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i] < nums[min_index]) {
                min_index = i;
            }
            if(nums[i] > nums[max_index]) {
                max_index = i;
            }
        }

        int del = n;
        if(min_index < max_index) {
            del = min({max_index + 1, n - min_index, (min_index + 1) + (n - max_index)});
        } else {
            del = min({min_index + 1, n - max_index, (max_index + 1) + (n - min_index)});
        }
        return del;
    }
};
