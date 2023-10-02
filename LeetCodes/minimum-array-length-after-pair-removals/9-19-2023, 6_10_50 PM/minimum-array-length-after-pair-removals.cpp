// Link: https://leetcode.com/problems/minimum-array-length-after-pair-removals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-array-length-after-pair-removals
 *  RUNTIME: 200 ms
 *  MEMORY: 164.2 MB
 *  DATE: 9-19-2023, 6:10:50 PM
 *
 */

// Solution:

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        int maxi = 0;
        for(auto &val: nums) {
            cnt[val]++;
            maxi = max(maxi, cnt[val]);
        }
        
        if(maxi <= n/2) return n % 2;
        return 2*maxi - n;
    }
};
