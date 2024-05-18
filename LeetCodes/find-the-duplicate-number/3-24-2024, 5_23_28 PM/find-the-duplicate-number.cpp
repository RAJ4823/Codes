// Link: https://leetcode.com/problems/find-the-duplicate-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-duplicate-number
 *  RUNTIME: 175 ms
 *  MEMORY: 104.3 MB
 *  DATE: 3-24-2024, 5:23:28 PM
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
