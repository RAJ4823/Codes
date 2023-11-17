// Link: https://leetcode.com/problems/find-the-k-or-of-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-k-or-of-an-array
 *  RUNTIME: 12 ms
 *  MEMORY: 27.2 MB
 *  DATE: 10-31-2023, 7:16:11 PM
 *
 */

// Solution:

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(auto &val: nums) {
            int x = val, pos = 0;
            while(x > 0) {
                cnt[pos++] += (x & 1);
                x >>= 1;
            }
        }
        int ans = 0;
        for(auto &[pos, count]: cnt) {
            if(count >= k) {
                ans += (1 << pos);
            }
        }
        return ans;
    }
};
