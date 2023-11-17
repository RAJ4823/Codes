// Link: https://leetcode.com/problems/find-target-indices-after-sorting-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-target-indices-after-sorting-array
 *  RUNTIME: 11 ms
 *  MEMORY: 11.9 MB
 *  DATE: 10-10-2023, 1:32:12 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();    

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] == target)
                ans.push_back(i);
        return ans;
    }
};
