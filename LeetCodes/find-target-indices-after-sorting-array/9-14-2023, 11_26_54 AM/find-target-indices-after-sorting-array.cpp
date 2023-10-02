// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-target-indices-after-sorting-array
 *  RUNTIME: 0 ms
 *  MEMORY: 12.2 MB
 *  DATE: 9-14-2023, 11:26:54 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> ans;
        for(int i=start; i<end; i++) 
            ans.push_back(i);
        return ans;
    }
};
