// Link: https://leetcode.com/problems/single-number-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: single-number-ii
 *  RUNTIME: 11 ms
 *  MEMORY: 10 MB
 *  DATE: 7-4-2023, 5:34:06 PM
 *
 */

// Solution:

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int ans = 0;
        for(auto &val: nums) {
            cnt[val]++;
        }
        for(auto &x: cnt) {
            if(x.second == 1) {
                ans = x.first;
                break;
            }
        }
        return ans;
    }
};
