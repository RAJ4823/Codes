// Link: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: ways-to-split-array-into-good-subarrays
 *  RUNTIME: 331 ms
 *  MEMORY: 235.2 MB
 *  DATE: 6-27-2023, 10:24:20 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, previ = n;
        vector<int> diffs;
        
        
        long long ways = 1;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) {
                int diff = i - previ;
                if(diff > 0) {
                    ways = (ways%mod * diff%mod) % mod;
                }
                previ = i;
            }
        }
        if(previ == n) return 0;
        return ways;
    }
};
