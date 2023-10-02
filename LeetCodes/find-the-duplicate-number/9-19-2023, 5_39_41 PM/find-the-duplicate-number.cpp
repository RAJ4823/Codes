// Link: https://leetcode.com/problems/find-the-duplicate-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-duplicate-number
 *  RUNTIME: 205 ms
 *  MEMORY: 101 MB
 *  DATE: 9-19-2023, 5:39:41 PM
 *
 */

// Solution:

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = nums[0];
        for(auto &val: nums) {
            mp[val]++;
            if(mp[val] > 1) {
                ans = val;
            }
        }
        return ans;
    }
};
