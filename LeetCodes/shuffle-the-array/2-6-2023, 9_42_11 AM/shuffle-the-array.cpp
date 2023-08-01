// Link: https://leetcode.com/problems/shuffle-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shuffle-the-array
 *  RUNTIME: 3 ms
 *  MEMORY: 9.9 MB
 *  DATE: 2-6-2023, 9:42:11 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n;
        vector<int> ans;
        while(i < n) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }
        return ans;
    }
};
