// Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-number-of-pairs-with-absolute-difference-k
 *  RUNTIME: 4 ms
 *  MEMORY: 13.5 MB
 *  DATE: 9-13-2023, 9:38:16 AM
 *
 */

// Solution:

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(auto &val: nums) {
            if(mp.find(val-k) != mp.end())
                ans += mp[val-k];
            if(mp.find(val+k) != mp.end())
                ans += mp[val+k];
            mp[val]++;
        }
        return ans;
    }
};
