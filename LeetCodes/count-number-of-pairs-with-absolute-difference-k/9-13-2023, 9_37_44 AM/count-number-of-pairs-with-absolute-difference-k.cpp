// Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-number-of-pairs-with-absolute-difference-k
 *  RUNTIME: 17 ms
 *  MEMORY: 14.6 MB
 *  DATE: 9-13-2023, 9:37:44 AM
 *
 */

// Solution:

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(auto &val: nums) {
            ans += (mp[val - k] + mp[val + k]);
            mp[val]++;
        }
        return ans;
    }
};
