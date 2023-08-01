// Link: https://leetcode.com/problems/first-missing-positive

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-missing-positive
 *  RUNTIME: 76 ms
 *  MEMORY: 41 MB
 *  DATE: 7-4-2023, 5:44:52 PM
 *
 */

// Solution:

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        for(auto &val: nums) {
            if(val == ans)
                ans++;
        }
        return ans;
    }
};
