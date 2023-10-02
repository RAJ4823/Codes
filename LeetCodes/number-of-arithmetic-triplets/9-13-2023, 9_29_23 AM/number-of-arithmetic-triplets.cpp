// Link: https://leetcode.com/problems/number-of-arithmetic-triplets

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-arithmetic-triplets
 *  RUNTIME: 5 ms
 *  MEMORY: 8.5 MB
 *  DATE: 9-13-2023, 9:29:23 AM
 *
 */

// Solution:

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<bool> vis(201, false);
        int ans = 0;

        for(auto &val: nums) {
            ans += (val - 2*diff >= 0) && vis[val - diff] && vis[val - 2*diff];
            vis[val] = true;
        } 
        return ans;
    }
};
