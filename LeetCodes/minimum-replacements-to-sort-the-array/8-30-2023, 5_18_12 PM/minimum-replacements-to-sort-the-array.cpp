// Link: https://leetcode.com/problems/minimum-replacements-to-sort-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-replacements-to-sort-the-array
 *  RUNTIME: 83 ms
 *  MEMORY: 54.7 MB
 *  DATE: 8-30-2023, 5:18:12 PM
 *
 */

// Solution:

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long count = 0;
        long long mini = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            long long val = nums[i];
            long long parts = ceil(val / (double)mini);
            count += parts - 1;
            mini = val/parts;
        }
        return count;
    }
};
