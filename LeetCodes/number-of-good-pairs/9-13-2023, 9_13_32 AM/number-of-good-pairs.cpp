// Link: https://leetcode.com/problems/number-of-good-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-good-pairs
 *  RUNTIME: 0 ms
 *  MEMORY: 7.2 MB
 *  DATE: 9-13-2023, 9:13:32 AM
 *
 */

// Solution:

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto &val: nums) {
            count[val]++;
        }

        int ans = 0;
        for(auto &x: count) {
            ans += (x.second * (x.second - 1))/2;
        }
        return ans;
    }
};
